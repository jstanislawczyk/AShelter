#include "IdSequence.h"
#include "Printer.h"

const string IdSequence::FILE_ID_SEQUENCE_NAME = "id_sequence.txt";

void IdSequence::init() {
	fstream idSequenceFile;
	idSequenceFile.open(IdSequence::FILE_ID_SEQUENCE_NAME, ios::out | ios::in);

	if (idSequenceFile.is_open()) {
		string idStatus = "";
		getline(idSequenceFile, idStatus);

		if (idStatus.empty()) {
			idSequenceFile.clear();
			idSequenceFile << "id:0";
		}

		idSequenceFile.close();
	} else {
		const string errorMessage = "Couldn't open " + IdSequence::FILE_ID_SEQUENCE_NAME + " file";
		Printer::println(errorMessage, Printer::RED);
	}
}

unsigned long int IdSequence::getNextId() {
	fstream idSequenceFile;
	idSequenceFile.open(IdSequence::FILE_ID_SEQUENCE_NAME, ios::out | ios::in);

	if (idSequenceFile.is_open()) {
		const unsigned long int previousId = this->getPreviousId(idSequenceFile);
		const unsigned long int nextId = previousId + 1;
		this->incrementIdInFile(nextId, idSequenceFile);

		idSequenceFile.close();

		return nextId;
	} else {
		const string errorMessage = "Couldn't open " + IdSequence::FILE_ID_SEQUENCE_NAME + " file";
		Printer::println(errorMessage, Printer::RED);

		return 0;
	}
}

unsigned long int IdSequence::getPreviousId(fstream& idSequenceFile) {
	string idStatus = "";
	getline(idSequenceFile, idStatus);

	return stoi(idStatus.substr(idStatus.find("\:") + 1, idStatus.length() - 1));
}

void IdSequence::incrementIdInFile(unsigned long int nextId, fstream& idSequenceFile) {
	idSequenceFile.clear();
	idSequenceFile.seekg(0, ios::beg);
	idSequenceFile << "id:" << nextId;
}
