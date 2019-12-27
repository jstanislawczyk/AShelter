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