#include "manager.hpp"
#include "file_directory.hpp"
#include <iostream>
#include <string>

Manager::Manager()
{
	currentDir = new FileDirectory();
	root = currentDir;
}

//lists all files/directories in current directory
void Manager::ls(FileDirectory &tempDir)
{
	FileDirectory* tempDir2 = &tempDir;
	if(tempDir2->getChild() == nullptr)
	{
		std::cout << "there are no files or directories in this directory\n";
	}
	else
	{
		std::cout << tempDir2->getName() << " has the following children:\n";
		tempDir2 = tempDir2->getChild();
		while(tempDir2 != nullptr){
			if(tempDir2->getDirectory() == true)
			{
			std::cout << "D ";
			}
			else
			{
				std::cout << "F ";
			}
			std::cout << tempDir2->getName() << std::endl;
			tempDir2 = tempDir2->getSibling();	
		};
	}
}

FileDirectory* Manager::mkdir(std::string name, bool isDir)
{
	FileDirectory* newDir = new FileDirectory(name, isDir);
	newDir->setParent(currentDir);
	newDir->setSibling(currentDir->getChild());
	currentDir->setChild(newDir);
	std::cout << currentDir->getChild()->getName() << std::endl;
	return currentDir;
}

//changes active directory. if ".." then change to parent.
void Manager::cd(std::string name)
{
	FileDirectory* tempDir;
	if(name == "..")
	{
		tempDir = currentDir->getParent();
	}
	else
	{
		tempDir = search(name, currentDir->getChild());
	}

	if(tempDir != nullptr && tempDir->getDirectory() != false)
	{
		currentDir = tempDir;
		std::cout << pwd(currentDir);
	}
	else
	{
		std::cout << "that directory does not exist.";
	}
}

//gives path of current directory as "Sarah/root/nextdir/etc"
std::string Manager::pwd(FileDirectory* tempDir)
{
	std::string totalPath = "";
	
	while(tempDir != nullptr){
		totalPath = ("/" + tempDir->getName()) + totalPath;
		tempDir = tempDir->getParent();
	}
	
	totalPath = "Sarah" + totalPath +"\n";
	
	return totalPath;
}

//renames directory/file nameA to nameB
void Manager::mv(std::string nameA, std::string nameB)
{
	//need to implement a search for nameA
	FileDirectory* tempDir = search(nameA, currentDir->getChild());
	tempDir->setName(nameB);
}

//makes deep copy of directory/file nameA to nameB
void Manager::cp(std::string nameA, std::string nameB)
{
	FileDirectory* tempDir = search(nameA, currentDir->getChild());
	FileDirectory* tempDir2 = new FileDirectory(*tempDir);
	tempDir2->setName(nameB);
	FileDirectory* tempSib = currentDir->getChild();
	tempDir2->setSibling(tempSib);
	currentDir->setChild(tempDir2);
	tempDir2->setParent(currentDir);
}

//locates and deletes file or directory
void Manager::rm(FileDirectory* tempDir)
{

}

//exits the program
void Manager::bye()
{
	//must send all files to be deleted
}

FileDirectory* Manager::search(std::string name, FileDirectory* tempDir)
{
	FileDirectory* tempDir2;
	if(tempDir->getName() == name)
	{
		return tempDir;
	}
	else if(tempDir->getSibling() != nullptr || tempDir->getChild() !=nullptr)
	{
		if(tempDir->getSibling() != nullptr)
		{
			tempDir2 = search(name, tempDir->getSibling());
		}
		if(tempDir->getChild() != nullptr)
		{
			FileDirectory* tempDir2 = search(name, tempDir->getChild());
		}
	}
	
	return tempDir2;
}

void Manager::handler(std::string command[21][3])
{
	for(int i = 0; i < 21; i++){
	std::cout << "command: " << i << std::endl;
	if(command[i][0] == "ls")
	{
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
		std::cout << pwd(currentDir);
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
		std::cout << pwd(tempDir->getParent());
	}}
}
