/*

#pragma once
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

bool checkFileExtension(string input);

vector<string> split(string str, string delim);

bool checkNumberOfCommas(string input);

void map_validator(string path);

class Country {
public:
	string name;
	string x_pos;
	string y_pos;
	string territory;
	vector<Country *> adjacent_countries;
	Country();
	Country(string Name, string X_pos, string Y_pos, string Territory, vector<Country *> aCountries);
};
*/