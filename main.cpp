#include "file_reader.hpp"
#include "manager.hpp"
#include "file_directory.hpp"
#include <iostream>

int main()
{
	FileDirectory dir1 = new Directory();
	dir1.setName("dir1");
	cout << dir1.getName() << endl;
	return 0;
}
