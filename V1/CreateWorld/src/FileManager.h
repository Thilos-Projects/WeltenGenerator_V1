#pragma once
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <filesystem>


#include "json.hpp"


namespace File_Manager {
	void setWorldPath(std::string path);
	void createFolder(std::string path);
	void removeFolder(std::string path);
}