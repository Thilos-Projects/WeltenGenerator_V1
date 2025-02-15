#include <stdint.h>
#include <iostream>
#include <fstream>

#include "src/json.hpp"
#include "src/FileManager.h"

#include "src/Jasonable.h"

std::string worldPath = "data/World1";

void funcTestFileWriter() {
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

	std::cout << File_Manager::createFile("HI", "test.txt") << std::endl;
	std::ofstream writer = File_Manager::writeFile("HI", "test.txt");
	writer << "Huhu" << std::endl;
	writer.close();
	std::ifstream reader = File_Manager::readFile("HI", "test.txt");
	std::string temp;
	reader >> temp;
	std::cout << temp << std::endl;
	reader.close();
	File_Manager::removeFile("HI", "test.txt");
	std::cout << File_Manager::folderExists("HI") << std::endl;
	std::cout << File_Manager::fileExists("HI", "test.txt") << std::endl;
	File_Manager::removeFolder("HI");
	std::cout << File_Manager::folderExists("HI") << std::endl;
	std::cout << File_Manager::fileExists("HI", "test.txt") << std::endl;
}

struct Version : public Jasonable {
	std::string Recourcen;
	std::string RecourcenOverview;


	virtual bool fillFromJson(nlohmann::json data) {
		if (!data.contains("Recourcen"))
			return false;
		if (!data.contains("RecourcenOverview"))
			return false;

		Recourcen = data["Recourcen"];
		RecourcenOverview = data["RecourcenOverview"];
		return true;
	}
	virtual nlohmann::json toJson() {
		nlohmann::json toRet;
		toRet["Recourcen"] = Recourcen;
		toRet["RecourcenOverview"] = RecourcenOverview;
		return toRet;
	}
};

struct Recource : public Jasonable {
	std::string name;


	virtual bool fillFromJson(nlohmann::json data) {
		if (!data.contains("name"))
			return false;

		name = data["name"];
		return true;
	}
	virtual nlohmann::json toJson() {
		nlohmann::json toRet;
		toRet["name"] = name;
		return toRet;
	}
};

std::map<std::string, std::string> recourcesOverview;

uint8_t main(int argc, char* argv[]) {
	
	if (argc > 1)
		worldPath = argv[1];
	File_Manager::setWorldPath(worldPath);

	Recource temp; std::ofstream writer; nlohmann::json toWrite;

	Version v;
	v.Recourcen = "V0001";
	v.RecourcenOverview = "V0001";
	File_Manager::createFile("", "Version.json");
	writer = File_Manager::writeFile("", "Version.json");
	if (!writer.is_open()) {
		std::cout << "Fehler beim beschreiben der datei" << std::endl;
		return -1;
	}
	toWrite = v.toJson();
	writer << toWrite.dump(1);
	writer.close();




	temp.name = "Demo";
	File_Manager::createFile("Recources", temp.name + ".json");
	writer = File_Manager::writeFile("Recources", temp.name + ".json");
	if (!writer.is_open()) {
		std::cout << "Fehler beim beschreiben der datei" << std::endl;
		return -1;
	}
	toWrite = temp.toJson();
	writer << toWrite.dump(1);
	writer.close();
	recourcesOverview.insert(std::make_pair(temp.name, "Recources/" + temp.name + ".json"));
	

	File_Manager::createFile("Overviews", "Recources.json");
	writer = File_Manager::writeFile("Overviews", "Recources.json");
	if (!writer.is_open()) {
		std::cout << "Fehler beim beschreiben der datei" << std::endl;
		return -1;
	}
	toWrite = recourcesOverview;
	writer << toWrite.dump(1);
	writer.close();

	return 0;
}