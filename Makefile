
appname=test

CXX=clang++
CXXFLAGS=-std=c++20 -Wall -Weffc++ -Wextra -Wsign-conversion
SOURCE_DIRECTORY=./src/
TARGET_DIRECTORY=./build/
LIB_DIRECTORY=./lib/
TEST_DIRECTORY=./test/

#TODO: sort this to make the makefile more robust
#%.o: %.cpp %.hpp								#For each file compiled to an object, take the name of the file.cpp and file.hpp and compile to object
#	$(CXX) $(CXXFLAGS) -c $^

$(shell mkdir -p $(TARGET_DIRECTORY))
$(shell mkdir -p $(TEST_DIRECTORY))

all: cliTool __testBackend

cliTool: $(TARGET_DIRECTORY)cliTool

__testBackend: $(TEST_DIRECTORY)__testBackend

# look into excludes

$(TARGET_DIRECTORY)backend.o: $(SOURCE_DIRECTORY)/backend.cpp
	$(CXX) $(CXXFLAGS) -c $(SOURCE_DIRECTORY)backend.cpp -o $(TARGET_DIRECTORY)backend.o

$(TARGET_DIRECTORY)cliTool.o: $(SOURCE_DIRECTORY)/cliTool.cpp
	$(CXX) $(CXXFLAGS) -c $(SOURCE_DIRECTORY)cliTool.cpp -o $(TARGET_DIRECTORY)cliTool.o

$(TARGET_DIRECTORY)cliTool: $(TARGET_DIRECTORY)cliTool.o $(TARGET_DIRECTORY)backend.o
	$(CXX) $(CXXFLAGS) $(TARGET_DIRECTORY)cliTool.o $(TARGET_DIRECTORY)backend.o -o $(TARGET_DIRECTORY)cliTool



# testing
$(TEST_DIRECTORY)catch2.o: $(TEST_DIRECTORY)catch2.o
	$(CXX) $(CXXFLAGS) $(LIB_DIRECTORY)catch_amalgamated.cpp -c -o $(TEST_DIRECTORY)catch2.o

$(TEST_DIRECTORY)__testBackend.o: $(SOURCE_DIRECTORY)__testBackend.cpp
	$(CXX) $(CXXFLAGS) $(SOURCE_DIRECTORY)__testBackend.cpp -c -o $(TEST_DIRECTORY)__testBackend.o

$(TEST_DIRECTORY)__testBackend: $(TEST_DIRECTORY)catch2.o $(TEST_DIRECTORY)__testBackend.o
	$(CXX) $(CXXFLAGS) $(TEST_DIRECTORY)__testBackend.o $(TEST_DIRECTORY)catch2.o -o $(TEST_DIRECTORY)__testBackend

clean:
	rm -r $(TARGET_DIRECTORY)
	rm -r $(TEST_DIRECTORY)
