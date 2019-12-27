#include "ShelterController.h"
#include "IdSequence.h"

ShelterController::~ShelterController() {
	Printer::println("Application closed", Printer::GREEN);
}

void ShelterController::init() {
	Shelter shelter = Shelter();

	this->printMainPage(shelter);
}

void ShelterController::chooseOption(Shelter& shelter) {
	cout << "Choose an option: ";

	int userChoice;
	cin >> userChoice;
	cout << endl;

	switch (userChoice) {
	case 1:
		this->showAnimals(shelter);
		this->printMainPage(shelter);
		break;
	case 2:
		this->addAnimal(shelter);
		this->printMainPage(shelter);
		break;
	case 3:
		this->updateAnimal(shelter);
		this->printMainPage(shelter);
		break;
	case 4:
		this->deleteAnimal(shelter);
		this->printMainPage(shelter);
		break;
	default:
		shelter.~Shelter();
		break;
	}
}

void ShelterController::printMainPage(Shelter& shelter) {
	Printer::println(shelter.getName(), Printer::BLUE);
	cout << endl;
	cout << "1. Show animals" << endl;
	cout << "2. Add animal" << endl;
	cout << "3. Edit animal" << endl;
	cout << "4. Delete animal" << endl;
	cout << "5. Exit" << endl;

	this->chooseOption(shelter);
}

void ShelterController::showAnimals(Shelter& shelter) {
	ifstream fileAnimalRegister;
	string fileLine = "";

	fileAnimalRegister.open(Shelter::FILE_ANIMAL_REGISTER_NAME);
	this->showCurrentShelterCapacity(shelter);
	Printer::println("Animals list", Printer::BLUE);

	while (getline(fileAnimalRegister, fileLine)) {
		if (!fileLine.empty()) {
			cout << "Id: " << fileLine << endl;
			getline(fileAnimalRegister, fileLine);

			cout << "Name: " << fileLine << endl;
			getline(fileAnimalRegister, fileLine);

			cout << "Age: " << fileLine << endl;
			getline(fileAnimalRegister, fileLine);

			cout << "Type: " << fileLine << endl;
			getline(fileAnimalRegister, fileLine);

			cout << "Breed: " << fileLine << endl << endl;
		}
	}

	fileAnimalRegister.close();
}

void ShelterController::showCurrentShelterCapacity(Shelter& shelter) {
	Printer::Color color = Printer::GREEN;
	const bool isShelterAlmostFull = shelter.getQuantityOfFreePlaces() <= 5;
	 
	if (shelter.isFullShelter()) {
		color = Printer::RED;
	} else if (isShelterAlmostFull) {
		color = Printer::ORANGE;
	}

	Printer::println("Current animals quantity", Printer::BLUE, true);
	Printer::println(to_string(shelter.getCurrentCapacity()) + "/" + to_string(shelter.getMaximumCapacity()), color);
	cout << endl;
}

void ShelterController::addAnimal(Shelter& shelter) {
	ofstream animalFileRegister;

	if (shelter.isFullShelter()) {
		Printer::println("Shelter is full", Printer::RED, true);
		return;
	}

	animalFileRegister.open(Shelter::FILE_ANIMAL_REGISTER_NAME, ios::app);

	if (animalFileRegister.is_open()) {
		Animal createdAnimal = setupAnimalData();

		this->saveAnimalToFile(createdAnimal, animalFileRegister);
		shelter.incrementCurrentCapacity();
		Printer::println("Animal created", Printer::GREEN, true);

		animalFileRegister.close();
	} else {
		const string errorMessage = "Couldn't open " + Shelter::FILE_ANIMAL_REGISTER_NAME + " file";
		Printer::println(errorMessage, Printer::RED);
	}
}

void ShelterController::updateAnimal(Shelter& shelter) {
	fstream animalFileRegister;
	animalFileRegister.open(Shelter::FILE_ANIMAL_REGISTER_NAME, ios::in);

	if (animalFileRegister.is_open()) {
		unsigned long int animalId = -1;

		Printer::println("Update animal", Printer::BLUE);
		cout << "Animal id for update: ";
		cin >> animalId;

		Animal updatedAnimal = setupAnimalData(animalId);
		this->updateAnimalInFile(updatedAnimal, animalFileRegister);
	}
	else {
		const string errorMessage = "Couldn't open " + Shelter::FILE_ANIMAL_REGISTER_NAME + " file";
		Printer::println(errorMessage, Printer::RED);
	}
}

void ShelterController::deleteAnimal(Shelter& shelter) {
	fstream animalFileRegister;
	animalFileRegister.open(Shelter::FILE_ANIMAL_REGISTER_NAME, ios::in);

	if (animalFileRegister.is_open()) {
		unsigned long int animalId = -1;
		
		Printer::println("Delete animal", Printer::BLUE);
		cout << "Animal id for delete: ";
		cin >> animalId;

		const bool isAnimalDeleted = deleteAnimalFromFile(animalId, animalFileRegister);

		if (isAnimalDeleted) {
			shelter.decrementCurrentCapacity();
		}
	}
	else {
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

	animal.setId(IdSequence::getNextId());
	animal.setName(animalName);
	animal.setAge(animalAge);
	animal.setType(animalType);
	animal.setBreed(animalBreed);

	return animal;
};

Animal ShelterController::setupAnimalData(unsigned long int animalId) {
	Animal animal = Animal();

	Printer::println("Leave variable empty if you don't want to update it", Printer::ORANGE);

	cout << endl;
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

	animal.setId(animalId);
	animal.setName(animalName);
	animal.setAge(animalAge);
	animal.setType(animalType);
	animal.setBreed(animalBreed);

	return animal;
};

void ShelterController::updateAnimalInFile(Animal updatedAnimal, fstream& animalFileRegister) {
	ofstream templateAnimalFileRegister(Shelter::FILE_TEMP_ANIMAL_REGISTER_NAME);

	char* animalFileRegisterNameAsChar = new char[Shelter::FILE_ANIMAL_REGISTER_NAME.length() + 1];
	char* templateAnimalFileRegisterNameAsChar = new char[Shelter::FILE_TEMP_ANIMAL_REGISTER_NAME.length() + 1];
	strcpy_s(animalFileRegisterNameAsChar, Shelter::FILE_ANIMAL_REGISTER_NAME.length() + 1, Shelter::FILE_ANIMAL_REGISTER_NAME.c_str());
	strcpy_s(templateAnimalFileRegisterNameAsChar, Shelter::FILE_TEMP_ANIMAL_REGISTER_NAME.length() + 1, Shelter::FILE_TEMP_ANIMAL_REGISTER_NAME.c_str());

	const unsigned int idLineNumberMultiplier = 7;
	const unsigned int shiftToNextId = 6;
	unsigned int currentLineNumber = 1;
	bool isAnimalUpdated = false;
	string fileLine = "";

	while (getline(animalFileRegister, fileLine)) {
		bool isAnimalIdLine = currentLineNumber % shiftToNextId == 1;
		bool isAnimalIdForUpdate = fileLine.compare(to_string(updatedAnimal.getId())) == 0;

		if (isAnimalIdLine && isAnimalIdForUpdate) {
			Animal previousAnimal = Animal();

			getline(animalFileRegister, fileLine);
			previousAnimal.setName(fileLine);

			getline(animalFileRegister, fileLine);
			previousAnimal.setAge(stoi(fileLine));

			getline(animalFileRegister, fileLine);
			previousAnimal.setType(fileLine);

			getline(animalFileRegister, fileLine);
			previousAnimal.setBreed(fileLine);

			this->saveAnimalToFileWithOptionalData(updatedAnimal, previousAnimal, templateAnimalFileRegister);
			isAnimalUpdated = true;
		} else if (fileLine.empty()) {
			templateAnimalFileRegister << endl;
		} else {
			templateAnimalFileRegister << fileLine << endl;
		}

		currentLineNumber++;
	}

	if (isAnimalUpdated) {
		Printer::println("Animal updated\n", Printer::GREEN);
	} else {
		Printer::println("Animal not found\n", Printer::RED);
	}

	animalFileRegister.close();
	templateAnimalFileRegister.close();

	remove(animalFileRegisterNameAsChar);
	rename(templateAnimalFileRegisterNameAsChar, animalFileRegisterNameAsChar);
}

void ShelterController::saveAnimalToFile(Animal animal, ofstream& animalFileRegister) {
	animalFileRegister << animal.getId() << endl;
	animalFileRegister << animal.getName() << endl;
	animalFileRegister << animal.getAge() << endl;
	animalFileRegister << animal.getType() << endl;
	animalFileRegister << animal.getBreed() << endl << endl;
}

void ShelterController::saveAnimalToFileWithOptionalData(Animal updatedAnimal, Animal previousAnimal, ofstream& animalFileRegister) {

	animalFileRegister << updatedAnimal.getId() << endl;

	updatedAnimal.getName().empty()
		? animalFileRegister << previousAnimal.getName() << endl
		: animalFileRegister << updatedAnimal.getName() << endl;

	updatedAnimal.getAge() == 0
		? animalFileRegister << previousAnimal.getAge() << endl
		: animalFileRegister << updatedAnimal.getAge() << endl;

	updatedAnimal.getType().empty()
		? animalFileRegister << previousAnimal.getType() << endl
		: animalFileRegister << updatedAnimal.getType() << endl;

	updatedAnimal.getBreed().empty()
		? animalFileRegister << previousAnimal.getBreed() << endl
		: animalFileRegister << updatedAnimal.getBreed() << endl;
}

bool ShelterController::deleteAnimalFromFile(unsigned long int animalId, fstream& animalFileRegister) {
	ofstream templateAnimalFileRegister(Shelter::FILE_TEMP_ANIMAL_REGISTER_NAME);

	char* animalFileRegisterNameAsChar = new char[Shelter::FILE_ANIMAL_REGISTER_NAME.length() + 1];
	char* templateAnimalFileRegisterNameAsChar = new char[Shelter::FILE_TEMP_ANIMAL_REGISTER_NAME.length() + 1];
	strcpy_s(animalFileRegisterNameAsChar, Shelter::FILE_ANIMAL_REGISTER_NAME.length() + 1, Shelter::FILE_ANIMAL_REGISTER_NAME.c_str());
	strcpy_s(templateAnimalFileRegisterNameAsChar, Shelter::FILE_TEMP_ANIMAL_REGISTER_NAME.length() + 1, Shelter::FILE_TEMP_ANIMAL_REGISTER_NAME.c_str());

	const unsigned int idLineNumberMultiplier = 7;
	const unsigned int shiftToNextId = 6;
	unsigned int currentLineNumber = 1;
	bool isAnimalDeleted = false;
	string fileLine = "";

	while (getline(animalFileRegister, fileLine)) {
		bool isAnimalIdLine = currentLineNumber % shiftToNextId == 1;
		bool isAnimalIdForDelete = fileLine.compare(to_string(animalId)) == 0;

		if (isAnimalIdLine && isAnimalIdForDelete) {
			for (int i = 0; i < shiftToNextId - 1; i++) {
				getline(animalFileRegister, fileLine);
			}

			isAnimalDeleted = true;
		} else if (fileLine.empty()) {
			templateAnimalFileRegister << endl;
		} else {
			templateAnimalFileRegister << fileLine << endl;
		}

		currentLineNumber++;
	}

	if (isAnimalDeleted) {
		Printer::println("Animal deleted\n", Printer::GREEN);
	} else {
		Printer::println("Animal not found\n", Printer::RED);
	}

	animalFileRegister.close();
	templateAnimalFileRegister.close();

	remove(animalFileRegisterNameAsChar);
	rename(templateAnimalFileRegisterNameAsChar, animalFileRegisterNameAsChar);

	return isAnimalDeleted;
}