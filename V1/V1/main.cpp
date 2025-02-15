#include <stdint.h>
#include <iostream>
#include <fstream>



#include "src/json.hpp"



uint8_t main() {
	std::cout << "Hello World" << std::endl;

	std::ifstream file("data/test.json");

	return 0;
}