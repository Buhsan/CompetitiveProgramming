import os
import sys
import requests
from bs4 import BeautifulSoup

API_URL = "https://codeforces.com/api/contest.standings"
PROBLEM_URL_TEMPLATE = "https://codeforces.com/contest/{contest_id}/problem/{problem_index}"

TEMPLATE_FILE = "template.cpp"

def create_launch_sh(folder_name):
    launch_content = """#!/bin/bash
g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -o main main.cpp
if [ $? -eq 0 ]; then
    ./main < input.txt > output.txt
    cat output.txt
else
    echo "Compilation failed."
fi
"""
    launch_path = os.path.join(folder_name, "launch.sh")
    with open(launch_path, "w") as f:
        f.write(launch_content)
    os.chmod(launch_path, 0o755)

def download_testcases(contest_id, problem_index, problem_folder):
    url = PROBLEM_URL_TEMPLATE.format(contest_id=contest_id, problem_index=problem_index)
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36"
    }
    response = requests.get(url, headers=headers)
    if response.status_code != 200:
        print(f"Error al obtener los casos de prueba para el problema {problem_index}: {response.status_code}")
        return
    
    soup = BeautifulSoup(response.text, 'html.parser')
    inputs = soup.find_all('div', class_='input')
    outputs = soup.find_all('div', class_='output')
    
    if not inputs or not outputs:
        print(f"No se encontraron casos de prueba para el problema {problem_index}.")
        return
    
    input_path = os.path.join(problem_folder, "input.txt")
    output_path = os.path.join(problem_folder, "output.txt")
    with open(input_path, "w") as input_file, open(output_path, "w") as output_file:
        for inp, out in zip(inputs, outputs):
            input_text = inp.find('pre').get_text(separator="\n").strip()
            output_text = out.find('pre').get_text(separator="\n").strip()
            
            input_file.write(input_text + '\n\n')
            output_file.write(output_text + '\n\n')

def setup_problem(contest_folder, contest_id, problem_index):
    problem_folder = os.path.join(contest_folder, problem_index)
    os.makedirs(problem_folder, exist_ok=True)
    
    main_cpp_path = os.path.join(problem_folder, "main.cpp")
    if os.path.exists(TEMPLATE_FILE):
        with open(TEMPLATE_FILE, "r") as template_file:
            template_content = template_file.read()
        with open(main_cpp_path, "w") as main_cpp_file:
            main_cpp_file.write(template_content)
    else:
        print(f"Plantilla '{TEMPLATE_FILE}' no encontrada. Creando archivo vacío.")
        open(main_cpp_path, "w").close()
    
    download_testcases(contest_id, problem_index, problem_folder)
    
    create_launch_sh(problem_folder)

def get_problems_from_contest(contest_id):
    response = requests.get(API_URL, params={"contestId": contest_id, "from": 1, "count": 1})
    if response.status_code != 200:
        print(f"Error al conectarse a la API: {response.status_code}")
        return None
    data = response.json()
    if data["status"] != "OK":
        print(f"Error en la API: {data.get('comment', 'Desconocido')}")
        return None
    
    problems = data["result"]["problems"]
    return [problem["index"] for problem in problems]

def main():
    if len(sys.argv) < 2:
        print("Uso: python3 setup_codeforces.py <contest_id>")
        sys.exit(1)
    
    contest_id = sys.argv[1]
    contest_folder = str(contest_id)
    os.makedirs(contest_folder, exist_ok=True)
    
    problems = get_problems_from_contest(contest_id)
    if problems is None:
        print("No se pudieron obtener los problemas.")
        return
    
    print(f"Creando carpetas para el contest {contest_id}...")
    for problem_index in problems:
        print(f"Configurando problema {problem_index}...")
        setup_problem(contest_folder, contest_id, problem_index)
    
    print("Problemas generados con éxito")

if __name__ == "__main__":
    main()
