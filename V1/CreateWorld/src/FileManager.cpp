#include "FileManager.h"


namespace fs = std::filesystem;

namespace File_Manager {
	std::string worldPath;

	void setWorldPath(std::string path) {
		worldPath = path + "/";
	}

	bool pathExists(std::string path){
		return fs::exists(worldPath + path);
	}

	bool folderExists(std::string path) {
		return pathExists(path);

	}
	bool createFolder(std::string path) {
		return fs::create_directories(worldPath + path);
	}
	void removeFolder(std::string path) {
		removePath(path);
	}

	bool createFile(std::string parrentFolder, std::string name) {
		createFolder(parrentFolder);
		std::ofstream ofs(worldPath + parrentFolder + "/" + name);
		bool isOpen = ofs.is_open();
		ofs.close();
		return isOpen;
	}
	void removeFile(std::string parrentFolder, std::string name) {
		removePath(parrentFolder + "/" + name);
	}
	bool fileExists(std::string parrentFolder, std::string name) {
		return pathExists(parrentFolder + "/" + name);
	}

	std::ifstream readFile(std::string parrentFolder, std::string name) {
		return std::ifstream(worldPath + "/" + parrentFolder + "/" + name);
	}
	std::ofstream writeFile(std::string parrentFolder, std::string name) {
		return std::ofstream(worldPath + "/" + parrentFolder + "/" + name);
	}
}