#pragma once

#include "map_validator.h"

using namespace std;

//temporary Country class for country name and territory comparison 
class Country {
public:
	Country() {
		name = "";
		x_pos = "";
		y_pos = "";
		territory = "";
	}

	Country(string Name, string X_pos, string Y_pos, string Territory, vector<string> aCountries) {

	}

private:
	
	string name;
	string x_pos;
	string y_pos;
	string territory;
	vector<string> adjacent_countries;

};


void map_validator (string file_path) {
	
	//open file for reading only
	//
	//Change to file_path later
	//
	fstream map_file("../maps/D-Day/D-Day.map", ios::in);
	
	//checks to see if the file succesfully opened
	if (map_file.is_open()) {
		
		//temporary string to store each line being loaded from the file
		//approach loads one line at a time and parses it based on what the temp string is
		string line;

		//map configuration vector which holds the header info
		vector<string> map_config;

		//Continents name vector 
		vector<string> continents_list;
		
		//Countries Vector containing continents
		vector<vector <string>> countries_list;

		//loop to load each line
		while (!map_file.eof()) {

			getline(map_file, line);

			//checks the file header
			if (line == "[Map]") {
				
				//go to next line
				getline(map_file, line);

				while (1) {

					if (line.find("author=") != string::npos) {
						map_config.push_back(line);
					}
					else if (line.find("image=") != string::npos) {
						map_config.push_back(line);
					}
					else if (line.find("wrap=") != string::npos) {
						map_config.push_back(line);
					}
					else if (line.find("scroll=") != string::npos) {
						map_config.push_back(line);
					}
					else if (line.find("warn=") != string::npos) {
						map_config.push_back(line);
					}
					else {
						break;
					}
				}
			}
			//load the continents string names into a vector for comparison later
			else if (line == "[Continents]") {

				while (1) {
				
					getline(map_file, line);
					
					//find() returns the position of the first occurence of matching string, returns -1 if not found
					//string::npos is -1 meaning no position found
					if (line.find("=") != string::npos) {
						
						size_t position = line.find("=");
						string temp_name = line.substr(0, position);
						
						//just keep continent name for comparison no need to keep the score
						continents_list.push_back(temp_name);
					}
				}
			}
			else if (line == "[Territories]") {
				
				while (1) {
					
					getline(map_file, line);

					if (checkNumberOfCommas(line)) {
						
						size_t position;
						string temp_string;
						
						if (line.find(",") != string::npos) {
							position = line.find(",");
							temp_string = line.substr(0, position);
						}
					}
					else {
						cout << "There is an error in the Territories section of the map file." << endl;
					}
				}
			}

		}
		map_file.close();
	}
	else {
		cout << "There was an error opening your file." << endl;
	}
}


//returns a vector of strings split by the delimeter
vector<string> split(string str, string delim) {

	vector<string> temp_container;

	while (str.find(delim) != string::npos) {
		
		size_t position = str.find(delim);
		temp_container.push_back(str.substr(0, position));
		string temp = str.substr(position+1);
		
		str = temp;
		
		if (str.find(delim) == string::npos) {
			temp_container.push_back(str);
		}
	}

	return temp_container;
}

//use to check the file extension, uses find_last_of in case there are more than one period in
//the file name
bool checkFileExtension(string input) {
	
	size_t position;
	string temp;

	if (input.find_last_of(".") != string::npos) {
		position = input.find(".");
		temp = input.substr(position + 1);
		if (temp == "txt" || temp == "map") {

			return true;
		}
	}
	cout << "Invalid file extension" << endl;
	return false;
}

//check the country string if there are less than 4 commas then the line must be invalid
//count function from the "algorithm library"
bool checkNumberOfCommas(string input) {
	size_t numOfCommas = count(input.begin(), input.end(), ',');

	return numOfCommas >= 4;
}