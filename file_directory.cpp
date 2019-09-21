#include "file_directory.hpp"
#include <string>
#include <iostream>

//for declaring root
FileDirectory::FileDirectory()
{
	parent = nullptr;
	child = nullptr;
	sibling = nullptr;
	name = "root";
	isDirectory = true;
}

//copy constructor
FileDirectory::FileDirectory(const FileDirectory& origFileDir)
{
	parent = origFileDir.parent;
	sibling = nullptr;
	child = nullptr;
	name = origFileDir.name;
	isDirectory = origFileDir.isDirectory;
}

//for declaring any directories and files
//isDir = true is directory
FileDirectory::FileDirectory(std::string newName, bool isDir)
{
	parent = nullptr;
	child = nullptr;
	sibling = nullptr;
	name = newName;
	isDirectory = isDir;
}

//destructor, for in event of "bye" command
FileDirectory::~FileDirectory()
{

}

//for updating parent
void FileDirectory::setParent(FileDirectory* newParent)
{
	parent = newParent;
}

//for getting parent
FileDirectory* FileDirectory::getParent()
{
	return parent;
}

//for updating child
void FileDirectory::setChild(FileDirectory* newChild)
{
	child = newChild;
}

//for getting child
FileDirectory* FileDirectory::getChild()
{
	return child;
}

//for updating sibling
void FileDirectory::setSibling(FileDirectory* newSibling)
{
	sibling = newSibling;
}


//for getting sibling
FileDirectory* FileDirectory::getSibling()
{
	return sibling;
}


//for updating name
void FileDirectory::setName(std::string newName)
{
	name = newName;
}

//for getting name
std::string FileDirectory::getName()
{
	return name;
}


//for updating if directory
void FileDirectory::setDirectory(bool isDir)
{
	isDirectory = isDir;
}

//for getting if directory
bool FileDirectory::getDirectory()
{
	return isDirectory;
}
