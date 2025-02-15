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
	File_Manager::createFolder("HI");

	uint8_t temp;
	std::cin >> temp;

	return 0;
}