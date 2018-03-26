// note: each triangle object is written in this way: {1, 2, 3, 4, 5, 6, 7, 8, 9}\n
#include "ReadLevelInfo.h"

ReadWriteLevelInfo::ReadWriteLevelInfo() {
	filename = "LevelData/tempFileName.txt";
}

std::string ReadWriteLevelInfo::validateInput() {
	bool validInput = false;
	std::string invalidChars = "0123456789!@#$%^&*()_+-=<>?,./;':\"[] {}\\\n";
	std::string userInput;

	while (validInput == false) {
		validInput = true;
		std::cout << "Enter a new filename: ";
		std::getline(std::cin, userInput);
		for (int i = 0; i < userInput.length(); i++) {
			if (invalidChars.find(userInput[i]) != -1) {
				std::cout << "Invalid character! Please only enter letters" << std::endl;
				validInput = false;
			}
		}
	}
	return userInput;
}

void ReadWriteLevelInfo::changeFilename() {
	std::string input = validateInput();
	std::string newFilename = "LevelData/";
	newFilename = newFilename + input + ".txt";
	std::cout << newFilename << std::endl;
	filename = newFilename;
}

std::vector<drawTriangle*> ReadWriteLevelInfo::readFile() {
	std::vector<drawTriangle*> triangleList;
	drawTriangle* newT = new drawTriangle();
	triangleList.push_back(newT);
	return triangleList;
}

void ReadWriteLevelInfo::writeFile(std::vector<drawTriangle*> triangles) {
	std::ofstream ofstr;
	ofstr.open(filename);

	for (int i = 0; i < triangles.size(); i++) {
		ofstr << "{";
		for (int z = 0; z < 9; z++) {
			//write to file index i
			if (z < 9 - 1) {
				ofstr << triangles.at(i)->vertices.at(z) << ",";
			}
			else {
				ofstr << triangles.at(i)->vertices.at(z);
			}
		}
		ofstr << "}\n";
	}
	ofstr.close();
}