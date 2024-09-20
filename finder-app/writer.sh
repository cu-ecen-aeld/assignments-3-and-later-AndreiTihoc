#!/bin/bash

# Check if both arguments are provided
if [ $# -ne 2 ]; then
    echo "Error: Two arguments required. Usage: $0 <writefile> <writestr>"
    exit 1
fi

writefile=$1
writestr=$2

# Extract the directory path from the writefile argument
dir=$(dirname "$writefile")

# Create the directory if it doesn't exist
mkdir -p "$dir"

# Check if directory was successfully created
if [ $? -ne 0 ]; then
    echo "Error: Could not create directory $dir"
    exit 1
fi

# Write the string to the file, overwriting if the file already exists
echo "$writestr" > "$writefile"

# Check if the file was successfully created
if [ $? -ne 0 ]; then
    echo "Error: Could not write to file $writefile"
    exit 1
fi

echo "File created successfully with content: $writestr"
exit 0
