CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -Wno-sign-compare


COMMON_SRC = $(filter-out src/main_hierarchy.cpp src/main_contracts.cpp, $(wildcard src/*.cpp))

all: hierarchy contracts

hierarchy: src/main_hierarchy.cpp $(COMMON_SRC)
	$(CXX) $(CXXFLAGS) src/main_hierarchy.cpp $(COMMON_SRC) -o hierarchy

contracts: src/main_contracts.cpp $(COMMON_SRC)
	$(CXX) $(CXXFLAGS) src/main_contracts.cpp $(COMMON_SRC) -o contracts

clean:
	rm -f hierarchy hierarchy.exe contracts contracts.exe