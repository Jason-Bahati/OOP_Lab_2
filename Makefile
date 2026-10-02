CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -Wno-sign-compare


COMMON_SRC = $(filter-out src/main_inheritance.cpp src/main_contracts.cpp, $(wildcard src/*.cpp))

all: inheritance contracts

inheritance: src/main_inheritance.cpp $(COMMON_SRC)
	$(CXX) $(CXXFLAGS) src/main_inheritance.cpp $(COMMON_SRC) -o inheritance

contracts: src/main_contracts.cpp $(COMMON_SRC)
	$(CXX) $(CXXFLAGS) src/main_contracts.cpp $(COMMON_SRC) -o contracts

clean:
	rm -f inheritance inheritance.exe contracts contracts.exe