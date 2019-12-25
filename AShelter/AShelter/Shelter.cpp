#include "Shelter.h"

Shelter::Shelter() {
	this->setupInitialCapacity();
}

void Shelter::setupInitialCapacity() {
	ifstream fileAnimalRegister;
	int animalsQuantity = 0;
	string fileLine = "";

	fileAnimalRegister.open(Shelter::FILE_ANIMAL_REGISTER_NAME);

	while (getline(fileAnimalRegister, fileLine)) {
		if (fileLine.empty()) {
			animalsQuantity++;
		}
	}

	this->setCurrentCapacity(animalsQuantity);
}

void Shelter::incrementCurrentCapacity() {
	this->setCurrentCapacity(this->getCurrentCapacity() + 1);
}

void Shelter::decrementCurrentCapacity() {
	this->setCurrentCapacity(this->getCurrentCapacity() - 1);
}

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

const string Shelter::FILE_ANIMAL_REGISTER_NAME = "current_animals.txt";