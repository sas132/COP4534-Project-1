#ifndef FILEREAD
#define FILEREAD

#include <fstream>
#include <iostream>
#include <string>
#include "manager.hpp"

class FileReader
{
private:
	Manager *newMan;
public:
	FileReader();
	void testWords(std::string words);
};
#endif
