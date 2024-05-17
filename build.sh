g++ -std=c++20 -o gctrl \
-I/opt/homebrew/opt/hidapi/include/hidapi \
-L/opt/homebrew/opt/hidapi/lib \
-lhidapi \
../src/main.cpp && ./gctrl