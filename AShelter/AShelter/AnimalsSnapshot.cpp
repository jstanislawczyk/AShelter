#include "AnimalsSnapshot.h"

void AnimalsSnapshot::createSnapshot(Shelter& shelter) {
	cout << this->snapshotFileName << endl;
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
		this->setSnapshotFileName(fileName);
	}
}

AnimalsSnapshot::~AnimalsSnapshot() {

}