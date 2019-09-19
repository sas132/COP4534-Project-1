#include "manager.hpp"
#include "file_directory.hpp"
#include <iostream>
#include <string>

Manager::Manager()
{
	currentDir = new FileDirectory();
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

void Director::mkdir(std::string name, bool isDir)
{
	FileDirectory newDir = FileDirectory(name, isDir);
	newDir.setParent(currentDir);
	newDir.setSibling(currentDir->getChild());
	currentDir->setChild(&newDir);
	std::cout << currentDir->getChild()->getName() << std::endl;
}

//changes active directory. if ".." then change to parent.
void Manager::cd(std::string name)
{
	if(name == "..")
	{
		currentDir = currentDir->getParent();
	}
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

FileDirectory* Manager::search(std::string name, FileDirectory* tempDir)
{
	if(tempDir->getName() == name)
	{
		tempDir = tempDir->getParent();
		return tempDir;
	}
	else if(tempDir->getSibling() != nullptr || tempDir->getChild() !=nullptr)
	{
		if(tempDir->getSibling() != nullptr)
		{
			return search(name, tempDir->getSibling());
		}
		if(tempDir->getChild() != nullptr)
		{
			return search(name, tempDir->getChild());
		}
	}
	return nullptr;
}

void Manager::handler(std::string command[3][3])
{
	std::cout << "made it to the function\n";
	for(int i = 0; i < 3; i++){
	if(command[i][0] == "ls")
	{
		std::cout << "made it to the right command\n";
		ls(*currentDir);
	}
	else if(command[i][0] == "mkdir")
	{
		mkdir(command[i][1], true);
	}
	else if(command[i][0] == "cd")
	{
		cd(command[i][1]);
	}
	else if(command[i][0] == "pwd")
	{
		pwd(currentDir);
	}
	else if(command[i][0] == "addf")
	{
		mkdir(command[i][1], false);
	}
	else if(command[i][0] == "mv")
	{
		mv(command[i][1], command[i][2]);
	}
	else if(command[i][0] == "cp")
	{
		cp(command[i][1], command[i][2]);
	}
	else if(command[i][0] == "rm")
	{
		FileDirectory* tempDir = search(command[i][1], currentDir);
		rm(tempDir);
	}
	else if(command[i][0] == "bye")
	{
		rm(root);
	}
	else if(command[i][0] == "whereis")
	{
		FileDirectory* tempDir = search(command[i][1], currentDir);
		pwd(tempDir);
	}}
}
