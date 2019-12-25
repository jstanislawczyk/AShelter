#include "ShelterController.h"
#include "IdSequence.h"

void ShelterController::init() {
	Shelter shelter = Shelter();

	printMainPage(shelter);
}

void ShelterController::chooseOption(Shelter& shelter) {
	cout << "Choose an option: ";

	int userChoice;
	cin >> userChoice;
	cout << endl;

	switch (userChoice) {
	case 1:
		showAnimals(shelter);
		printMainPage(shelter);
		break;
	case 2:
		addAnimal(shelter);
		printMainPage(shelter);
		break;
	default:
		Printer::println("Application closed", Printer::GREEN);
		break;
	}
}

void ShelterController::showAnimals(Shelter& shelter) {
	ifstream fileAnimalRegister;
	string fileLine = "";

	fileAnimalRegister.open(Shelter::FILE_ANIMAL_REGISTER_NAME);

	Printer::println("Current animals quantity", Printer::BLUE, true);
	cout << shelter.getCurrentCapacity() << "/" << shelter.getMaximumCapacity() << endl << endl;
	Printer::println("Animals list", Printer::BLUE);

	while (getline(fileAnimalRegister, fileLine)) {
		cout << fileLine << endl;
	}

	fileAnimalRegister.close();
}

void ShelterController::addAnimal(Shelter& shelter) {
	ofstream fileRegister;
	fileRegister.open(Shelter::FILE_ANIMAL_REGISTER_NAME, ios::app);

	if (fileRegister.is_open()) {
		Animal createdAnimal = setupAnimalData();
		saveAnimalToFile(createdAnimal, fileRegister);
		shelter.incrementCurrentCapacity();

		fileRegister.close();
	} else {
		const string errorMessage = "Couldn't open " + Shelter::FILE_ANIMAL_REGISTER_NAME + " file";
		Printer::println(errorMessage, Printer::RED);
	}
}

Animal ShelterController::setupAnimalData() {
	Animal animal = Animal();

	cout << "Enter animal name: ";
	string animalName;
	cin >> animalName;

	cout << "Enter animal age: ";
	int animalAge;
	cin >> animalAge;

	cout << "Enter animal type (e.g. dog): ";
	string animalType;
	cin >> animalType;

	cout << "Enter animal breed: ";
	string animalBreed;
	cin >> animalBreed;

	cout << endl;
	Printer::println("Animal created", Printer::GREEN);
	cout << endl;

	animal.setId(IdSequence::getNextId());
	animal.setName(animalName);
	animal.setAge(animalAge);
	animal.setType(animalType);
	animal.setBreed(animalBreed);

	return animal;
};

void ShelterController::saveAnimalToFile(Animal animal, ofstream& fileRegister) {
	fileRegister << animal.getId() << endl;
	fileRegister << animal.getName() << endl;
	fileRegister << animal.getAge() << endl;
	fileRegister << animal.getType() << endl;
	fileRegister << animal.getBreed() << endl << endl;
}

void ShelterController::printMainPage(Shelter& shelter) {
	Printer::println(shelter.getName(), Printer::BLUE);
	cout << endl;
	cout << "1. Show animals" << endl;
	cout << "2. Add animal" << endl;
	cout << "3. Edit animal" << endl;
	cout << "4. Delete animal" << endl;
	cout << "5. Exit" << endl;

	chooseOption(shelter);
}