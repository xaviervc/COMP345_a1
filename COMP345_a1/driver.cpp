#pragma once
#include "map_validator.h"
#include "MapValidator.h"

using namespace std;

int main() {
	//test section
	string filePath = "../maps/Alabama/Alabama.map";

	MapValidator test(filePath);

	test.validateFile();

	cin.get();
}