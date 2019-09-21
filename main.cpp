#include "file_reader.hpp"
#include <iostream>

int main()
{
	//dir1 = directory
	//FileDirectory dir1;
	//dir1.setName("dir1");
//	std::cout << dir1.getName() << std::endl;

	//fil1 = file
//	FileDirectory fil1("fil1");
//	std::cout << std::endl << fil1.getName() << std::endl << std::endl;

//	fil1.setParent(&dir1);
//	dir1.setChild(&fil1);
//	std::cout << "fil1's parent: " << fil1.getParent()->getName() << std::endl;
//	std::cout << "dir1's child: " << dir1.getChild()->getName() << std::endl << std::endl;
	
	//dir2 = directory
//	FileDirectory dir2("dir2", true);
//	dir2.setParent(&dir1);
//	dir2.setSibling(dir1.getChild());
//	dir1.setChild(&dir2);
//	std::cout << "dir2's parent: " << dir2.getParent()->getName() << std::endl;
//	std::cout << "dir2's sibling: " << dir2.getSibling()->getName() << std::endl;
//	std::cout << "dir1's child: " << dir1.getChild()->getName() << std:: endl;
//	std::cout << "fil1's parent: " << fil1.getParent()->getName() << std::endl;
	//fil1's sibling gets segmentation fault, works properly
	//std::cout << "fil1's sibling: " << fil1.getSibling()->getName() << std::endl << std::endl;
	
//	std::cout << "all file_directory tests pass" << std::endl << std::endl << std::endl;

	/*FileDirectory root = FileDirectory();
	FileDirectory dir3 = FileDirectory("dir3", true);
	root.setChild(&dir3);
	dir3.setParent(&root);
	FileDirectory dir4 = FileDirectory("dir4", false);
	dir4.setSibling(&dir3);
	root.setChild(&dir4);
	dir4.setParent(&root);

	Manager newMan;
	newMan.ls(root);
	std::cout << newMan.pwd(&dir3);
	newMan.mv(dir3, "directory 3");
	std::cout << newMan.pwd(&dir3);
	std::string test1 = "directory 3";
	std::string test2 = "dir3";
	//std::cout << newMan.whereis(test2, &root);*/
	

	/*Manager newMan;
	std::string commands[26][3] = {	{"ls", "", ""}, //0
					{"mkdir", "dir1", ""}, //1
					{"addf", "fil1", ""}, //2
					{"mkdir", "dir2", ""}, //3
					{"ls", "", ""}, //4
					{"cd", "dir2", ""}, //5
					{"pwd", "", ""}, //6
					{"cd", "..", ""}, //7
					{"mv", "fil1", "file 1"}, //8
					{"ls", "", ""}, //9
					{"cd", "dir2", ""}, //10
					{"addf", "file 2", ""}, //11
					{"cd", "..", ""}, //12
					{"cp", "dir2", "directory 2"}, //13
					{"ls", "", ""}, //14
					{"cd", "dir2", ""}, //15
					{"ls", "", ""}, //17
					{"mv", "file 2", "file file 2"}, //17
					{"cd", "..", ""}, //18
					{"cd", "directory 2", ""}, //19
					{"ls", "", ""}, //20
					{"cd", "..", ""}, //21
					{"ls", "", ""}, //22
					{"rm", "directory 2", ""}, //23
					{"ls", "", ""}, //24
					{"bye", "", ""} //25
				     };
	newMan.handler(commands);*/
	FileReader* newFile = new FileReader();
	return 0;
}
