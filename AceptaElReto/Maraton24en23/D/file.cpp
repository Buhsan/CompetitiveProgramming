#include <bits/stdc++.h>
using namespace std;

string obtener_clave(const string& palabra) {
    if (palabra.size() <= 3) return palabra;
    string clave;
    clave += palabra.front();
    string medio = palabra.substr(1, palabra.size() - 2);
    sort(medio.begin(), medio.end());
    clave += medio;
    clave += palabra.back();
    return clave;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        unordered_map<string, string> clave_a_palabra;
        unordered_map<string, bool> es_ambigua;
        unordered_map<string, bool> es_exacta;

        string linea;
        getline(cin, linea);
        stringstream ss1(linea);
        string palabra;
        while (ss1 >> palabra && palabra != ".") {
            string clave = obtener_clave(palabra);
            es_exacta[palabra] = true;
            if (!clave_a_palabra.count(clave)) {
                clave_a_palabra[clave] = palabra;
                es_ambigua[clave] = false;
            } else {
                es_ambigua[clave] = true;
            }
        }

        getline(cin, linea);
        stringstream ss2(linea);
        bool primero = true;
        while (ss2 >> palabra && palabra != ".") {
            if (!primero) cout << " ";
            primero = false;

            if (es_exacta.count(palabra)) {
                cout << palabra;
            } else {
                string clave = obtener_clave(palabra);
                if (!es_ambigua[clave] && clave_a_palabra.count(clave)) {
                    cout << clave_a_palabra[clave];
                } else {
                    cout << palabra;
                }
            }
        }
        cout << " ." << '\n';
    }
    return 0;
}
