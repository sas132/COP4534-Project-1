CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = file_reader.o manager.o directory.o file.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $

clean: $(RM) *.o *.gch core main test.cpp

testBuild: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -Itest/catch/catch.hpp -o test $(OBJECTS) test.cpp

test: clean testBuild
	test --success
