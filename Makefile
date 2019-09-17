CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = file_reader.o manager.o file_directory.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o *.gch core main
