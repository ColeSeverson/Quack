#!/bin/bash

#Script to run parser on argument then compile the c code it generates

#### Main

if ["$1" == ""]; then
    echo "Please invoke this script with ./quack.sh <filename>"
fi

echo "Running parser"

./bin/parser  $1
mv code.c codegen/
gcc -g -Wno-incompatible-pointer-types ./codegen/code.c codegen/Builtins.o
