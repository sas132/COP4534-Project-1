#include "manager.hpp"
#include "file_directory.hpp"
#include <iostream>
#include <string>

Manager::Manager()
{
	currentDir = new FileDirectory();
	root = currentDir;
}

Manager::~Manager()
{

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
		tempDir = search(name, currentDir);
	}

	if(tempDir != nullptr && tempDir->getDirectory() != false)
	{
		currentDir = tempDir;
		std::cout << pwd(currentDir);
	}
	else
	{
		std::cout << "that directory does not exist.\n";
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
	FileDirectory* tempDir = search(nameA, currentDir);
	if(tempDir == nullptr)
	{
		std::cout << "that file or directory does not exist.\n";
	}
	else
	{
		tempDir->setName(nameB);
	}
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
	
	tempDir = tempDir->getChild();
	
	while(tempDir != nullptr)
	{
		copySibling(tempDir, tempDir2);
		tempDir = tempDir->getSibling();
	}
}

void Manager::copySibling(FileDirectory* tempChild, FileDirectory* tempParent)
{
	FileDirectory* tempChildCopy = new FileDirectory(*tempChild);
	FileDirectory* tempSibl = tempParent->getChild();
	tempChildCopy->setSibling(tempSibl);
	tempParent->setChild(tempChildCopy);
	tempChildCopy->setParent(tempParent);

	if(tempChild->getChild() != nullptr)
	{
		copySibling(tempChild->getChild(), tempChild);
	}
}

//locates and deletes file or directory
void Manager::rm(FileDirectory* tempDir)
{
	if(tempDir->getChild() != nullptr)
	{
		deleteSiblings(tempDir->getChild());
	}
	if(tempDir->getName() != "root")
	{
		if(tempDir->getParent()->getChild()->getName() == tempDir->getName())
		{
			tempDir->getParent()->setChild(tempDir->getSibling());
		}
		else
		{
			FileDirectory* tempSib = tempDir->getParent()->getChild();
			while(tempSib->getSibling()->getName() != tempDir->getName())
			{	
				tempSib = tempSib->getSibling();
			}

			tempSib->setSibling(tempDir->getSibling());
		}
		delete tempDir;
	}
}

void Manager::deleteSiblings(FileDirectory* tempDir)
{
	if(tempDir->getChild() != nullptr)
	{
		deleteSiblings(tempDir->getChild());
	}
	if(tempDir->getSibling() != nullptr)
	{
		deleteSiblings(tempDir->getSibling());
	}
	delete tempDir;
}

FileDirectory* Manager::search(std::string name, FileDirectory* tempDir)
{
	if(tempDir->getName() == name)
	{
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
	else
	{
		return nullptr;
	}
}

void Manager::handler(std::string command, std::string firstWord, std::string secondWord)
{
	if(command == "ls")
	{
		ls(*currentDir);
	}
	else if(command == "mkdir")
	{
		mkdir(firstWord, true);
	}
	else if(command == "cd")
	{
		cd(firstWord);
	}
	else if(command == "pwd")
	{
		std::cout << pwd(currentDir);
	}
	else if(command == "addf")
	{
		mkdir(firstWord, false);
	}
	else if(command == "mv")
	{
		mv(firstWord, secondWord);
	}
	else if(command == "cp")
	{
		cp(firstWord, secondWord);
	}
	else if(command == "rm")
	{
		FileDirectory* tempDir = search(firstWord, currentDir);
		if(tempDir != nullptr)
		{
			rm(tempDir);
		}
		else
		{
			std::cout << firstWord << " does not exist.\n";
		}
	}
	else if(command == "bye")
	{
		rm(root);
	}
	else if(command == "whereis")
	{
		FileDirectory* tempDir = search(firstWord, root);
		if(tempDir != nullptr)
		{
			std::cout << pwd(tempDir->getParent());
		}
		else
		{
			std::cout << firstWord << " does not exist.\n";
		}
	}
}
