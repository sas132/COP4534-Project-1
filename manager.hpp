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
	Manager(); //how will this be used??
	void ls(); //lists all files/directories in current directory
	void mkdir(std::string name, bool isDir);
	void cd(std::string name); //changes active directory. if ".." then change to parent.
	std::string pwd(FileDirectory* currentDir); //gives path of current directory as "Sarah/root/nextdir/etc"
	void addf(std::string name); //adds a new file as child of current directory
	void mv(std::string nameA, std::string nameB); //renames directory/file nameA to nameB
	void cp(std::string nameA, std::string nameB); //makes deep copy of directory/file nameA to nameB
	void rm(FileDirectory* tempDir); //locates and deletes file or directory
	void bye(); //exits the program
	FileDirectory* search(std::string name, FileDirectory* tempDir);
	void handler(std::string command[3][3]);	
};

#endif
