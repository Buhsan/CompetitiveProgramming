clear
set +x
g++ "$(pwd)/$1.cpp" -o "$(pwd)/$1.out"
"$(pwd)/$1.out" < "$(pwd)/$1.txt"
