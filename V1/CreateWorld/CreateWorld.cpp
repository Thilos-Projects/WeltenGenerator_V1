#include <stdint.h>
#include <iostream>
#include <fstream>

#include "src/json.hpp"
#include "src/FileManager.h"

std::string worldPath = "data/World1";

uint8_t main(int argc, char* argv[]) {
	
	if (argc > 1)
		worldPath = argv[1];

	File_Manager::setWorldPath(worldPath);
	std::cout << File_Manager::createFolder("HI") << std::endl;
	std::cout << File_Manager::createFolder("HI") << std::endl;
	std::cout << File_Manager::folderExists("HI") << std::endl;
	File_Manager::removeFolder("HI");
	std::cout << File_Manager::folderExists("HI") << std::endl;

	std::cout << File_Manager::createFile("HI", "test.txt") << std::endl;
	std::cout << File_Manager::folderExists("HI") << std::endl;
	std::cout << File_Manager::fileExists("HI", "test.txt") << std::endl;
	File_Manager::removeFolder("HI");
	std::cout << File_Manager::folderExists("HI") << std::endl;
	std::cout << File_Manager::fileExists("HI", "test.txt") << std::endl;

	std::cout << File_Manager::createFile("HI", "test.txt") << std::endl;
	std::cout << File_Manager::folderExists("HI") << std::endl;
	std::cout << File_Manager::fileExists("HI", "test.txt") << std::endl;
	File_Manager::removeFile("HI", "test.txt");
	std::cout << File_Manager::folderExists("HI") << std::endl;
	std::cout << File_Manager::fileExists("HI", "test.txt") << std::endl;

	//uint8_t temp;
	//std::cin >> temp;

	return 0;
}