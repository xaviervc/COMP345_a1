#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class MapValidator {

public:
	MapValidator();
	~MapValidator();
	MapValidator(string filePath);
	bool checkHeaders();
	void validateFile();
	vector<string> getFileContents();
	void checkMapSection();
	void loadSections();


private:
	vector<string> fileContents;
	vector<string> mapSection;
	vector<string> contiSection;
	vector<string> countrySection;
};