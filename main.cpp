#include "file_reader.hpp"
#include "manager.hpp"
#include "directory.hpp"
#include "file.hpp"
#include <iostream>

int main()
{
	Directory dir1 = new Directory();
	dir1.setName("dir1");
	cout << dir1.getName() << endl;
	return 0;
}
