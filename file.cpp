#include "file.hpp"
#include "Directory.hpp"
#include <string>

File::File()
{
	parent = nullptr;
	sibling = nullptr;
	name = "NONE";
}

File::File(std::string newName)
{
	parent = nullptr;
	sibling = nullptr;
	name = newName;
}

void File::setParent(Directory* newParent)
{
	parent = newParent;
}

Directory* File::getParent()
{
	return parent;
}

void File::setSibling(T* newSibling)
{
	sibling = newSibling;
}

T* File::getSibling()
{
	return sibling;
}

void File::setName(std::string newName)
{
	name = newName;
}

std::string File::getName()
{
	return name;
}
