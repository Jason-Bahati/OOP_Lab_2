CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
SRC      = $(wildcard src/*.cpp)
TARGET   = main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)