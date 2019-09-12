#ifndef FILEHPP
#define FILEHPP

#include "Directory.hpp"
#include <string>>
template <typename T>
class File
{
private:
	Directory* parent;
	std::string name;
	T* sibling

public:
	File()
	File(std::string newName);
	void setParent(Directory* newParent);
	Directory* getParent();
	void setSibling(T* newSibling);
	T* getSibling();
	void setName(std::string newName);
	std::string getName();
}
