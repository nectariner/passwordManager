
appname=test

CXX=clang++
CXXFLAGS=-std=c++17 -Wall -Weffc++ -Wextra -Wsign-conversion
SOURCE_DIRECTORY=./src/
TARGET_DIRECTORY=./build/

#%.o: %.cpp %.hpp								#For each file compiled to an object, take the name of the file.cpp and file.hpp and compile to object
#	$(CXX) $(CXXFLAGS) -c $^

all: output

main.o: $(SOURCE_DIRECTORY)/main.cpp buildDir
	$(CXX) $(CXXFLAGS) -c $(SOURCE_DIRECTORY)main.cpp -o $(TARGET_DIRECTORY)main.o

encryption.o: $(SOURCE_DIRECTORY)/encryption.cpp buildDir
	$(CXX) $(CXXFLAGS) -c $(SOURCE_DIRECTORY)encryption.cpp -o $(TARGET_DIRECTORY)encryption.o
	
output: main.o encryption.o buildDir
	$(CXX) $(CXXFLAGS) $(TARGET_DIRECTORY)*.o -o $(TARGET_DIRECTORY)output
	
buildDir:
	mkdir build
	
run:
	$(TARGET_DIRECTORY)/output

clean:
	rm -r $(TARGET_DIRECTORY)/*
