#ifndef DIRECTOR
#define DIRECTOR

#include "file_directory.hpp"
#include "manager.hpp"
#include <iostream>
#include <string>

class Director
{
private:
	FileDirectory* currentDir;
	FileDirectory* root;
public:
	Director();
	void mkdir(std::string name, bool isDir);
	void cd(std::string name);
	void addf(std::string name);
	void mv(std::string nameA, std::string nameB);
	void cp(std::string nameA, std::string nameB);
	FileDirectory* search(std::string name, FileDirectory* tempDir);
	void rm(FileDirectory* tempDir);
	void handler(std::string command[3][3]);
};
#endif
