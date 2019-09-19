#include "manager.hpp"
#include "file_directory.hpp"
#include <iostream>
#include <string>

Manager::Manager()
{
	//currentDir = new FileDirectory();
}

void Manager::print()
{

}

//lists all files/directories in current directory
void Manager::ls(FileDirectory &currentDir)
{
	if(currentDir.getChild() == nullptr)
	{
		std::cout << "there are no files or directories in this directory\n";
	}
	else
	{
		std::cout << currentDir.getName() << " has the following children:\n";
		FileDirectory* tempDir = currentDir.getChild();

		while(tempDir != nullptr){
			if(tempDir->getDirectory() == true)
			{
				std::cout << "D ";
			}
			else
			{
				std::cout << "F ";
			}
			std::cout << tempDir->getName() << std::endl;
			tempDir = tempDir->getSibling();	
		};
	}
}

//changes active directory. if ".." then change to parent.
void Manager::cd(std::string name)
{

}

//gives path of current directory as "Sarah/root/nextdir/etc"
std::string Manager::pwd(FileDirectory* currentDir)
{
	std::string totalPath = "";
	FileDirectory* tempDir = currentDir;
	
	while(tempDir != nullptr){
		totalPath = ("/" + tempDir->getName()) + totalPath;
		tempDir = tempDir->getParent();
	}
	
	totalPath = "Sarah" + totalPath +"\n";
	
	return totalPath;
}

//renames directory/file nameA to nameB
void Manager::mv(FileDirectory &nameA, std::string nameB)
{
	//need to implement a search for nameA
	//temporarily using a call-by-reference
	
	nameA.setName(nameB);
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
	//must send all files to be deleted
}

//locates and prints location of first occurance of file/directory
std::string whereis(std::string name, FileDirectory* currentDir)
{
	/*if(currentDir->getName() == name)
	{
		currentDir = currentDir->getParent();
		return pwd(&currentDir);
	}
	else if(currentDir->getSibling() != nullptr || currentDir->getChild() != nullptr)
	{
		if(currentDir->getSibling() != nullptr)
		{
			return whereis(name, currentDir->getSibling());
		}
		if(currentDir->getChild() != nullptr)
		{
			return whereis(name, currentDir->getChild());
		}
	}*/
	return name + " not found.";
	
}
