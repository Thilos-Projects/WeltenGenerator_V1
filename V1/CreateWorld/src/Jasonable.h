#pragma once

#include "json.hpp"

struct Jasonable {
	virtual bool fillFromJson(nlohmann::json data) = 0;
	virtual nlohmann::json toJson() = 0;
};