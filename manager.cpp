#include "manager.hpp"
#include "file_directory.hpp"
#include <iostream>
#include <string>

Manager::Manager()
{
	currentDir = new FileDirectory();
}

void Manager::print()
{

}

//lists all files/directories in current directory
void Manager::ls()
{
	if(currentDir->getChild() == nullptr)
	{
		std::cout << "there are no files or directories in this directory\n";
	}
	else
	{
		FileDirectory* tempDir = currentDir;
		std::string allChilds= "";
	
		do{
			allChilds += (tempDir->getChild()->getName() + "\n");
			tempDir = tempDir->getChild();
		}while(tempDir->getChild() != nullptr);
		
		std::cout << allChilds;
	}
}

//makes a new directory as child of current directory
void Manager::mkdir(std::string name)
{
	FileDirectory newDir(name, true);
	newDir.setParent(currentDir);
	newDir.setSibling(currentDir->getChild());
	currentDir->setChild(&newDir);
}

//changes active directory. if ".." then change to parent.
void Manager::cd(std::string name)
{

}

//gives path of current directory as "Sarah/root/nextdir/etc"
void Manager::pwd()
{

}

//adds a new file as child of current directory
void Manager::addf(std::string name)
{

}

//renames directory/file nameA to nameB
void Manager::mv(std::string nameA, std::string nameB)
{

}

//makes deep copy of directory/file nameA to nameB
void Manager::cp(std::string nameA, std::string nameB)
{

}

//locates and deletes file or directory
void Manager::rm(std::string name)
{

}

//exits the program
void Manager::bye()
{

}

//locates and prints location of first occurance of file/directory
void whereis(std::string name)
{

}

FileDirectory* Manager::getCurrentDir()
{
	return currentDir;
}
