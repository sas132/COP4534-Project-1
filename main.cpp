#include "file_reader.hpp"
#include "manager.hpp"
#include "file_directory.hpp"
#include <iostream>

int main()
{
	FileDirectory dir1;
	dir1.setName("dir1");
	std::cout << dir1.getName() << std::endl;
	return 0;
}
