#include "file_reader.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "manager.hpp"

//default constructor, makes Manager and accepts input from commands.txt, sends commands to testWords
FileReader::FileReader()
{
	newMan = new Manager();
	
	std::ifstream fileInput;
	fileInput.open("commands.txt");
	std::string command;
	while(getline(fileInput, command))
	{
		testWords(command);
	}
}

//goes through each line, making the command, first, and second words to sent to Manager.handler
void FileReader::testWords(std::string words)
{
	char tempChar;
	int counter = 0;
	std::string command = "";
	std::string firstWord = "";
	std::string secondWord = "";

	if(words == "pwd" || words == "ls" || words == "bye")
	{
		command = words;
	}
	else
	{
		while(words[counter] != ' ')
		{
			tempChar = words[counter];
			command += tempChar;
			counter++;
		}

		counter++;
		
		while(words[counter] != ' ' && counter < words.length())
		{
			tempChar = words[counter];
			counter++;
			firstWord += tempChar;
		}
		
		if(command == "mv" || command == "cp")
		{
			counter++;
			while(counter < words.length())
			{
				tempChar = words[counter];
				counter++;
				secondWord += tempChar;
			}
		}
	}

	std::cout << "$ " << command << " " << firstWord << " " << secondWord << "\n";	
	newMan->handler(command, firstWord, secondWord);
	
	if(command == "bye")
	{
		delete newMan;
	}
}
