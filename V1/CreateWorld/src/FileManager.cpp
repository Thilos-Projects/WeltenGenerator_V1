#include "FileManager.h"


namespace fs = std::filesystem;

namespace File_Manager {
	std::string worldPath;


	void setWorldPath(std::string path) {
		worldPath = path + "/";
	}

	void createFolder(std::string path) {
		fs::create_directory(worldPath+path)
			? std::cout << "created directory - " << path << std::endl
			: std::cout << "create_directory() failed" << std::endl;

	}
	void removeFolder(std::string path) {

		fs::remove(worldPath+path);
	}

}