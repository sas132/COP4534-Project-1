#include "director.hpp"
#include "file_directory.hpp"
#include "manager.hpp"
#include <iostream>
#include <string>

Director::Director()
{
	root = new FileDirectory();
	currentDir = root;
}

void Director::mkdir(std::string name, bool isDir)
{
	FileDirectory newDir = FileDirectory(name, isDir);
	newDir.setParent(currentDir);
	newDir.setSibling(currentDir->getChild());
	currentDir->setChild(&newDir);
	std::cout << currentDir->getChild()->getName() << std::endl;
}

void Director::cd(std::string name)
{
	if(name == "..")
	{
		currentDir = currentDir->getParent();
	}
}

void Director::mv(std::string nameA, std::string nameB)
{

}

void Director::cp(std::string nameA, std::string nameB)
{

}

FileDirectory* Director::search(std::string name, FileDirectory* tempDir)
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

void Director::rm(FileDirectory* tempDir)
{

}

void Director::handler(std::string command[3][3])
{
	Manager newMan;
	std::cout << "made it to the function\n";
	for(int i = 0; i < 3; i++){
	if(command[i][0] == "ls")
	{
		std::cout << "made it to the right command\n";
		newMan.ls(*currentDir);
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
		newMan.pwd(currentDir);
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
		newMan.pwd(tempDir);
	}}
}
