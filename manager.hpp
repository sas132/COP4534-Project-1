#ifndef MANAGER
#define MANAGER

#include "file_directory.hpp"
#include <iostream>
#include <string>

class Manager
{
private:
	FileDirectory* currentDir;
public:
	Manager(); //how will this be used??
	void ls(FileDirectory &currentDir); //lists all files/directories in current directory
	//void mkdir(FileDirectory &currentDir, std::string name); //makes a new directory as child of current directory
	void cd(std::string name); //changes active directory. if ".." then change to parent.
	std::string pwd(FileDirectory* currentDir); //gives path of current directory as "Sarah/root/nextdir/etc"
	void addf(std::string name); //adds a new file as child of current directory
	void mv(FileDirectory &nameA, std::string nameB); //renames directory/file nameA to nameB
	void cp(std::string nameA, std::string nameB); //makes deep copy of directory/file nameA to nameB
	void rm(std::string name); //locates and deletes file or directory
	void bye(); //exits the program
	FileDirectory* search(std::string name, FileDirectory* tempDir);
	void handler(std::string command[3][3]);	
};

#endif
