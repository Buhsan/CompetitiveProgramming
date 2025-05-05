import subprocess
import os

def open_powershell_and_run():
    # Command to open PowerShell 7 and execute commands
    powershell_command = (
        'pwsh -NoExit -Command "cd d:\\cp; lvim"'
    )

    # Execute the command
    subprocess.run(powershell_command, shell=True)

if __name__ == "__main__":
    open_powershell_and_run()
