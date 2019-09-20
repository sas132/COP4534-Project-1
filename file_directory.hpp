#ifndef FILE_DIRECT
#define FILE_DIRECT

#include <string>

class FileDirectory
{
private:
	FileDirectory* parent;
	FileDirectory* child;
	FileDirectory* sibling;
	std::string name;
	//true = directory
	//false = file
	bool isDirectory;

public:
	FileDirectory();
	FileDirectory(const FileDirectory& origFileDir);
	FileDirectory(std::string newName);
	FileDirectory(std::string newName, bool isDir);
	void setParent(FileDirectory* newParent);
	FileDirectory* getParent();
	void setChild(FileDirectory* newChild);
	FileDirectory* getChild();
	void setSibling(FileDirectory* newSibling);
	FileDirectory* getSibling();
	void setName(std::string newName);
	std::string getName();
	void setDirectory(bool isDir);
	bool getDirectory();
};

#endif
