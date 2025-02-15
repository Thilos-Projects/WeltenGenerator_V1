#include "FileManager.h"


namespace fs = std::filesystem;

namespace File_Manager {
	std::string worldPath;


	void setWorldPath(std::string path) {
		worldPath = path + "/";
	}

	bool pathExists(std::string worldPath){
		if(worldPath)
	}

	
	bool createFolder(std::string path) {
		return fs::create_directories(worldPath + path);
	}
	void removeFolder(std::string path) {

		fs::remove(worldPath+path);
	}

	void createFile(std::string parrentFolder, std::string name) {
		createFolder(parrentFolder);
		std::ofstream ofs(worldPath + parrentFolder + "/" + name);
		ofs.close();
	}

}