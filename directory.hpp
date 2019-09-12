#ifndef DIRECT
#define DIRECT

#include <string>
template <typename T>
class Directory
{
private:
	Directory* parent;
	T* child;
	std::String name;
	T* sibling;

public:
	void setParent(Directory* newParent);
	Directory* getParent();
	void setChild(T* newChild);
	T* getChild();
	void setName(std::String newName);
	std::String getName();
	void setSibling(T* newSibling);
	T* getSibling();
}

#endif
