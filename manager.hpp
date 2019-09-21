#ifndef MANAGER
#define MANAGER

#include "file_directory.hpp"
#include <iostream>
#include <string>

class Manager
{
private:
	FileDirectory* currentDir;
	FileDirectory* root;
public:
	Manager();
	~Manager();
	void ls(FileDirectory &tempDir);
	FileDirectory* mkdir(std::string name, bool isDir);
	void cd(std::string name);
	std::string pwd(FileDirectory* currentDir);
	void addf(std::string name);
	void mv(std::string nameA, std::string nameB);
	void cp(std::string nameA, std::string nameB);
	void copySibling(FileDirectory* tempChild, FileDirectory* tempParent);
	void rm(FileDirectory* tempDir);
	void deleteSiblings(FileDirectory* tempDir);
	FileDirectory* search(std::string name, FileDirectory* tempDir);
	void handler(std::string command, std::string firstWord, std::string secondWord);	
};

#endif
