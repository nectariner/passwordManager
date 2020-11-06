
appname=test

CXX=clang++
CXXFLAGS=-std=c++20 -Wall -Weffc++ -Wextra -Wsign-conversion
SOURCE_DIRECTORY=./src/
TARGET_DIRECTORY=./build/

#TODO: sort this to make the makefile more robust
#%.o: %.cpp %.hpp								#For each file compiled to an object, take the name of the file.cpp and file.hpp and compile to object
#	$(CXX) $(CXXFLAGS) -c $^

all: output

main.o: $(SOURCE_DIRECTORY)/main.cpp build
	$(CXX) $(CXXFLAGS) -c $(SOURCE_DIRECTORY)main.cpp -o $(TARGET_DIRECTORY)main.o

encryption.o: $(SOURCE_DIRECTORY)/encryption.cpp build
	$(CXX) $(CXXFLAGS) -c $(SOURCE_DIRECTORY)encryption.cpp -o $(TARGET_DIRECTORY)encryption.o
	
output: main.o encryption.o build
	$(CXX) $(CXXFLAGS) $(TARGET_DIRECTORY)*.o -o $(TARGET_DIRECTORY)output
	
build: build
	mkdir build
	
run:
	$(TARGET_DIRECTORY)/output

run-encrypt:
	$(TARGET_DIRECTORY)/output encrypt caesarcipher 1

run-decrypt:
	$(TARGET_DIRECTORY)/output decrypt caesarcipher 1

clean:
	rm -r $(TARGET_DIRECTORY)/*
