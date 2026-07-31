g++ "$1.cpp" -O3 -o program && ./program <"tests/0$1" >"$1.out"
