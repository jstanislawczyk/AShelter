#include "Shelter.h"

string Shelter::getName() {
	return name;
}

int Shelter::getMaximumCapacity() {
	return maximumCapacity;
}

void Shelter::setCurrentCapacity(int currentCapacity) {
	this -> currentCapacity = currentCapacity;
}

int Shelter::getCurrentCapacity() {
	return currentCapacity;
}

const string Shelter::FILE_REGISTER_NAME = "current_animals.txt";