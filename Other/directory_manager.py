import os
import shutil
import string
import sys

# Fixed paths
DEFAULT_DIR = r"/home/buhsan/CP/1AAPLANTILLA/"
BASE_DIR = r"/home/buhsan/CP/"

def sanitize_input(input_string):
    """
    Removes leading/trailing whitespace and invisible characters from the input.
    """
    return ''.join(c for c in input_string.strip() if c.isprintable())

def copy_and_rename():
    """Mode 1: Copy and rename the default directory."""
    new_name = input("Enter the new name for the copied directory: ").strip()
    new_name = sanitize_input(new_name)
    
    if not new_name:
        print("Error: Invalid directory name provided.")
        return

    dest_dir = os.path.join(BASE_DIR, new_name)
    
    try:
        shutil.copytree(DEFAULT_DIR, dest_dir)
        print(f"Default directory successfully copied to '{dest_dir}'.")
    except FileExistsError:
        print(f"Error: The directory '{dest_dir}' already exists.")
    except Exception as e:
        print(f"Error: Failed to copy to '{dest_dir}'. Reason: {e}")

def create_multiple_copies():
    """Mode 2: Create a parent directory and copy the default directory multiple times."""
    parent_dir_name = input("Enter the name of the new parent directory: ").strip()
    parent_dir_name = sanitize_input(parent_dir_name)
    
    count = input("Enter the number of copies to create (X): ").strip()
    count = sanitize_input(count)

    if not parent_dir_name:
        print("Error: Invalid parent directory name provided.")
        return

    if not count.isdigit() or int(count) < 1:
        print("Error: Count must be a positive integer.")
        return

    count = int(count)
    parent_dir_path = os.path.join(BASE_DIR, parent_dir_name)

    try:
        os.makedirs(parent_dir_path, exist_ok=True)
    except Exception as e:
        print(f"Error: Failed to create parent directory '{parent_dir_path}'. Reason: {e}")
        return

    alphabet = string.ascii_uppercase
    for i in range(count):
        if i >= len(alphabet):
            print(f"Error: Cannot create more than {len(alphabet)} directories.")
            break

        subdir_name = alphabet[i]
        target_dir = os.path.join(parent_dir_path, subdir_name)
        try:
            shutil.copytree(DEFAULT_DIR, target_dir)
            print(f"Copied to '{target_dir}'.")
        except FileExistsError:
            print(f"Error: The directory '{target_dir}' already exists.")
        except Exception as e:
            print(f"Error: Failed to copy to '{target_dir}'. Reason: {e}")

def main():
    """Main function to run the script."""
    if not os.path.exists(DEFAULT_DIR):
        print(f"Error: Default directory '{DEFAULT_DIR}' does not exist.")
        return

    print("Select mode:")
    print("[1] Copy and rename default directory")
    print("[2] Create directory and copy default directory multiple times")
    choice = input("Enter your choice (1 or 2): ").strip()

    if choice == "1":
        copy_and_rename()
    elif choice == "2":
        create_multiple_copies()
    else:
        print("Invalid mode selected. Exiting.")

if __name__ == "__main__":
    main()
