#ifndef DIRECT
#define DIRECT

#include <string>
template <typename T>
class Directory
{
private:
	Directory* parent;
	T* child;
	std::string name;
	T* sibling;

public:
	Directory()
	Directory(std::string newName);
	void setParent(Directory* newParent);
	Directory* getParent();
	void setChild(T* newChild);
	T* getChild();
	void setName(std::string newName);
	std::string getName();
	void setSibling(T* newSibling);
	T* getSibling();
}

#endif
