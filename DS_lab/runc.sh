#!/bin/bash

# Check if there are at least two arguments

if [ "$#" -eq 1 ]; then
    gcc -o main.exe $1 -lm
    ./main.exe
    exit 0
fi

if [ "$#" -lt 2 ]; then
    echo "Usage: $0 <source_file1.c> <source_file2.c> ..."
    exit 1
fi

# Extract the last argument as the output executable name
output_name="main.exe"

# Compile each source file to object files
gcc "$@" -o "$output_name" -lm

if [ $? -ne 0 ]; then
    echo "Compilation failed for $output_name"
    exit 1
fi

./main.exe
exit 0