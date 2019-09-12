#include "directory.hpp"
#include <string>

Directory::Directory()
{
	parent = nullptr;
	child = nullptr;
	name = "NONE";
	sibling = nullptr;
}

Directory::Directory(std::string newName)
{
	parent = nullptr;
	child = nullptr;
	name = newName;
	sibling = nullptr;
}

void Directory::setParent(Directory* newParent)
{
	parent = newParent;
}

Directory* Directory::getParent()
{
	return parent;
}

void Directory::setChild(T* newChild)
{
	child = newChild;
}

T* Directory::getChild()
{
	return child;
}

void Directory::setName(std::string newName)
{
	name = newName;
}

std::string Directory::getName()
{
	return name;
}

void Directory::setSibling(T* newSibling)
{
	sibling = newSibling;
}

T* Directory::getSibling()
{
	return sibling;
}
