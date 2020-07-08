# Information-Retrieval-Library
A C++ Information Retrieval Library
It can be used directly in your project. Further contribution by anybody is welcome.
This library uses iostream, unordered_map, vector, cmath, string, utility, thread library hence it is dependent on it.
If not declared this library automatically calls this libraries.
This library is non supported to gcc compiler version below 201103.
To use this as a static library first convert it into object file using command "g++ -std=c++11 -o filename.o -c filename.cpp" and then use command "ar rvs filename.a filename.o" and include the header file in your program
