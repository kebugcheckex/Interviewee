#!/usr/bin/env bash

set -e

dir_name=$(basename "$PWD")

if [[ "$dir_name" != "InterviewPrep" ]]; then
    echo "Please run this script in the root dir"
    exit 1
fi

if [ $# -ne 1 ]; then
    echo "Usage: $0 problem-name"
    exit 1
fi

cp -r cpp_utils/cpp_template leetcode/"$1"
echo "add_subdirectory(\"leetcode/$1\")" >>CMakeLists.txt

echo "Done"
