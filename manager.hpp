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
	void print(); //is this going to be needed? idk yet
	void ls(); //lists all files/directories in current directory
	void mkdir(std::string name); //makes a new directory as child of current directory
	void cd(std::string name); //changes active directory. if ".." then change to parent.
	void pwd(); //gives path of current directory as "Sarah/root/nextdir/etc"
	void addf(std::string name); //adds a new file as child of current directory
	void mv(std::string nameA, std::string nameB); //renames directory/file nameA to nameB
	void cp(std::string nameA, std::string nameB); //makes deep copy of directory/file nameA to nameB
	void rm(std::string name); //locates and deletes file or directory
	void bye(); //exits the program
	void whereis(std::string name); //locates and prints location of first occurance of file/directory
};

#endif
