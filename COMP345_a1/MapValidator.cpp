#include "MapValidator.h"

MapValidator::MapValidator() {

}

MapValidator::~MapValidator() {

}

//pass a file path and it fills the entire contents of the string into a string vector
MapValidator::MapValidator(string filePath) {
	
	//check file extension first txt and map files only

	size_t position;
	string temp;

	if (filePath.find_last_of(".") != string::npos) {
		position = filePath.find_last_of(".");
		temp = filePath.substr(position + 1);
		
		if (temp == "txt" || temp == "map") {

			fstream mapFile(filePath, ios::in);

			if (mapFile.is_open()) {

				string readLine;
				
				while (!mapFile.eof()) {
					getline(mapFile, readLine);
					fileContents.push_back(readLine);
				}
			}

			mapFile.close();
		}

	}
	else {
		cout << "Invalid file extension." << endl;
	}
}

//checks to see if all 3 headers are there
bool MapValidator::checkHeaders() {
	
	int counter = 0;

	for (auto i : fileContents) {
		if (i == "[Map]") {
			counter++;
		}
		if (i == "[Continents]") {
			counter++;
		}
		if (i == "[Territories]") {
			counter++;
		}
	}

	if (counter != 3) {
		cout << "There is an error in the file headers." << endl;
	}

	return counter == 3;
}

//break file up into sections
void MapValidator::loadSections() {

	for (int i = 0; i < fileContents.size(); i++) {
		//first load the map section part of the vector
		if (fileContents[i] == "[Map]") {
			i++;
			while (fileContents[i] != "") {
				mapSection.push_back(fileContents[i]);
				i++;
			}
		}
		if (fileContents[i] == "[Continents]") {
			i++;
			while (fileContents[i] != "") {
				contiSection.push_back(fileContents[i]);
				i++;
			}
		}
		if (fileContents[i] == "[Territories]") {
			i++;
			while (i<fileContents.size()) {
				countrySection.push_back(fileContents[i]);
				i++;
			}
		}
	}
}

void MapValidator::checkMapSection() {

}

//the main validator
void MapValidator::validateFile() {
	
	if (checkHeaders()) {
		loadSections();
	}
}

vector<string> MapValidator::getFileContents()
{
	return fileContents;
}