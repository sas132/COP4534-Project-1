#include "file_directory.hpp"
#include <string>

//for declaring root
FileDirectory::FileDirectory()
{
	parent = nullptr;
	child = nullptr;
	sibling = nullptr;
	name = "root";
	isDirectory = true;
}

//for declaring any files
FileDirectory::FileDirectory(std::string newName)
{
	parent = nullptr;
	child = nullptr;
	sibling = nullptr;
	name = newName;
	isDirectory = false;
}

//for declaring any directories
FileDirectory::FileDirectory(std::string newName, bool isDir)
{
	parent = nullptr;
	child = nullptr;
	sibling = nullptr;
	name = newName;
	isDirectory = isDir;
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
