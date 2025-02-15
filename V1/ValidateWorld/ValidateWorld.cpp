#include <stdint.h>
#include <iostream>
#include <fstream>

#include "src/json.hpp"
#include "src/FileManager.h"

#include "src/Jasonable.h"

std::string worldPath = "data/World1";

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

	if (!File_Manager::fileExists("", "Version.json"))
		return -1;

	auto temp = File_Manager::readFile("", "Version.json");
	nlohmann::json toPrint = nlohmann::json::parse(temp);
	std::cout << toPrint.dump(2) << std::endl;

	return 0;
}