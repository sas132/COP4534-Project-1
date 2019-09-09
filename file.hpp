#ifndef FILEHPP
#define FILEHPP

#include "Directory.hpp"
#include <string>>
template <typename T>
class File
{
private:
	Directory* parent;
	std::String name;
	T* sibling

public:
	void setParent(Directory* newParent);
	Directory* getParent();
	void setSibling(T* newSibling);
	T* getSibling();
	void setName(std::String);
	std::String getName();
}
