#include "AnimalsSnapshot.h"

void AnimalsSnapshot::createSnapshot(Shelter& shelter) {
	ifstream fileAnimalRegister;
	ofstream fileAnimalRegisterSnapshot;
	string fileLine = "";
	Animal templateAnimal = Animal();
	Animal* animalsList = new Animal[shelter.getCurrentCapacity()];
	int iterator = 0;

	fileAnimalRegister.open(Shelter::FILE_ANIMAL_REGISTER_NAME);
	fileAnimalRegisterSnapshot.open(this->getSnapshotFileName());

	Printer::println("Animals list", Printer::BLUE);

	while (getline(fileAnimalRegister, fileLine)) {
		if (!fileLine.empty()) {
			templateAnimal.setId(stol(fileLine));
			getline(fileAnimalRegister, fileLine);

			templateAnimal.setName(fileLine);
			getline(fileAnimalRegister, fileLine);

			templateAnimal.setAge(stoi(fileLine));
			getline(fileAnimalRegister, fileLine);

			templateAnimal.setType(fileLine);
			getline(fileAnimalRegister, fileLine);

			templateAnimal.setBreed(fileLine);
			getline(fileAnimalRegister, fileLine);

			animalsList[iterator] = templateAnimal;

			iterator++;
		}
	}

	for (int i = 0; i < shelter.getCurrentCapacity(); i++) {
		fileAnimalRegisterSnapshot << (animalsList + i)->getId() << endl;
		fileAnimalRegisterSnapshot << (animalsList + i)->getName() << endl;
		fileAnimalRegisterSnapshot << (animalsList + i)->getAge() << endl;
		fileAnimalRegisterSnapshot << (animalsList + i)->getType() << endl;
		fileAnimalRegisterSnapshot << (animalsList + i)->getBreed() << endl << endl;
	}

	Printer::println("Snapshot created", Printer::GREEN, true);
	cout << endl;

	fileAnimalRegister.close();
	fileAnimalRegisterSnapshot.close();
}

string AnimalsSnapshot::getSnapshotDefaultFileName() {
	return this->defaultSnapshotFileName;
}

string AnimalsSnapshot::getSnapshotFileName() {
	return this->snapshotFileName;
}

void AnimalsSnapshot::setSnapshotFileName(string newSnapshotFileName) {
	this->snapshotFileName = newSnapshotFileName;
}

AnimalsSnapshot::AnimalsSnapshot() {
	string fileName = "";

	cout << "Enter snapshot file name: ";
	cin >> fileName;

	const bool isEqualToAnimalFileName = (fileName.compare(Shelter::FILE_ANIMAL_REGISTER_NAME)) == 0;

	if (isEqualToAnimalFileName) {
		Printer::println("Animal snapshot file name must be different than animal file name. Using default snapshot file name.", Printer::ORANGE, true);
		this->setSnapshotFileName(this->getSnapshotDefaultFileName());
	} else {
		this->setSnapshotFileName(fileName + ".txt");
	}
}

AnimalsSnapshot::~AnimalsSnapshot() {

}