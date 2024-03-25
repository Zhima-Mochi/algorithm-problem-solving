#!/bin/bash

# Loop through each file in the current directory
for file in *; do
    # Check if the file is the script itself or the README file
    # Get the file extension
    extension="${file##*.}"
    # Define a list of common programming language extensions
    common_extensions=("py" "js" "java" "c" "cpp" "cs" "go" "rb" "php" "swift" "kt" "rs" "sh" "md")
    # If the file is the script itself, the README file, or has an uncommon extension, skip it
    if [ "$file" == "move.sh" ] || [ "$file" == "README.md" ] || [[ ! " ${common_extensions[@]} " =~ " ${extension} " ]]; then
        continue
    fi
    # Check if the file is actually a file (not a directory or other special file)
    if [ -f "$file" ]; then
        # Get the file extension
        extension="${file##*.}"
        # Check if there's a directory with the same name as the extension
        if [ -d "$extension" ]; then
            # Move the file to the corresponding directory
            mv "$file" "$extension"
        else
            # If there's no directory with the same name as the extension, create one and move the file
            mkdir "$extension"
            mv "$file" "$extension"
        fi
    fi
done
