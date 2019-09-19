CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = file_directory.o manager.o file_reader.o director.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o *.gch core main
