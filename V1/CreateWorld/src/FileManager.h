#pragma once
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <filesystem>

#include <Windows.h>


#include "json.hpp"


namespace File_Manager {
	void setWorldPath(std::string path);

	bool folderExists(std::string path);
	bool createFolder(std::string path);
	void removeFolder(std::string path);

	bool createFile(std::string parrentFolder, std::string name);
	void removeFile(std::string parrentFolder, std::string name);
	bool fileExists(std::string parrentFolder, std::string name);
}