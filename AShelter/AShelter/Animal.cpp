#include "Animal.h"

Animal::Animal() {
	this->id = 0;
	this->name = "";
	this->age = 0;
	this->type = "";
	this->breed = "";
}

Animal::~Animal() {

}

bool Animal::operator ==(const Animal& animalToCompare) {
	const bool equalIds = animalToCompare.getId() == this->getId();
	const bool equalNames = animalToCompare.getName() == this->getName();
	const bool equalAges = animalToCompare.getAge() == this->getAge();
	const bool equalTypes = animalToCompare.getType() == this->getType();
	const bool equalBreeds = animalToCompare.getBreed() == this->getBreed();

	return equalIds && equalNames && equalAges && equalTypes && equalBreeds;
}

unsigned long int Animal::getId() const {
	return this->id;
}

string Animal::getName() const {
	return this->name;
}

int Animal::getAge() const {
	return this->age;
}

string Animal::getType() const {
	return this->type;
}

string Animal::getBreed() const {
	return this->breed;
}

void Animal::setId(unsigned long int id) {
	this->id = id;
}

void Animal::setName(string name) {
	this->name = name;
}

void Animal::setAge(int age) {
	this->age = age;
}

void Animal::setType(string type) {
	this->type = type;
}

void Animal::setBreed(string breed) {
	this->breed = breed;
}