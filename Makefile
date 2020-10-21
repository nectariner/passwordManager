
appname=test

CXX=clang++
CXXFLAGS=-std=c++14 -Wall -Weffc++ -Wextra -Wsign-conversion
SOURCE_DIRECTORY=./src/
TARGET_DIRECTORY=./build/

#%.o: %.cpp %.hpp								#For each file compiled to an object, take the name of the file.cpp and file.hpp and compile to object
#	$(CXX) $(CXXFLAGS) -c $^

all: output

main.o: $(SOURCE_DIRECTORY)/main.cpp
	$(CXX) $(CXXFLAGS) -c $(SOURCE_DIRECTORY)main.cpp -o $(TARGET_DIRECTORY)main.o
	
output: main.o
	$(CXX) $(CXXFLAGS) $(TARGET_DIRECTORY)/main.o -o $(TARGET_DIRECTORY)output
	
	
run:
	$(TARGET_DIRECTORY)/output

clean:
	rm -r $(TARGET_DIRECTORY)/*
