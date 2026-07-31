#!/bin/bash

# 1. Compile the C++ program
# We compile file.cpp into an executable named 'my_program'
echo "Compiling file.cpp..."
g++ file.cpp -O2 -o my_program

# Check if compilation was successful
if [ $? -ne 0 ]; then
  echo "Error: Compilation failed. Exiting."
  exit 1
fi

echo "Compilation successful. Running tests..."

# 2. Iterate through all files in the 'test' directory
for input_file in tests/*; do
  # Ensure it's a file (and not a subdirectory)
  if [ -f "$input_file" ]; then

    # Extract the base name of the file (e.g., '1.txt' from 'test/1.txt')
    base_name=$(basename "$input_file")

    # Strip the extension to get just the name (e.g., '1' from '1.txt')
    name_no_ext="${base_name%.*}"

    # Define the output filename (e.g., '1.out')
    output_file="${name_no_ext}.out"

    # Execute the program, redirecting the input file in and the output file out
    ./my_program <"$input_file" >"$output_file"

    echo "Processed $input_file -> $output_file"
  fi
done

# 3. Zip all .out files into ans.zip
echo "Zipping output files..."
# The -q flag makes it quiet, and -j strips directory paths if there were any
zip -q ans.zip *.out

echo "Done! All outputs have been saved to ans.zip."

# Optional cleanup: remove the compiled executable if you no longer need it
# rm my_program
