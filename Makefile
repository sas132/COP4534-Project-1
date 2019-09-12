CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = file_reader.o manager.o directory.o file.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean: $(RM) *.o *.gc* core main
