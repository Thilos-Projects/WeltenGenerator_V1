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

	bool fileExists(std::string path) {
		return pathExists(path);
	}

	bool folderExists(std::string path) {
		return pathExists(path);
	}

	void removePath(std::string path) {
		fs::remove(worldPath + path);
	}

	bool pathExists(std::string worldPath){
		//if(worldPath)
	}

	
	bool createFolder(std::string path) {
		return fs::create_directories(worldPath + path);
	}
	void removeFolder(std::string path) {
		removePath(path);
	}

	void createFile(std::string parrentFolder, std::string name) {
		createFolder(parrentFolder);
		std::ofstream ofs(worldPath + parrentFolder + "/" + name);
		ofs.close();
	}
	void removeFile(std::string parrentFolder, std::string name) {
		removePath(parrentFolder + "/" + name);
	}

}