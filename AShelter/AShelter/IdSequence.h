#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class IdSequence {
	private:
		unsigned long int getPreviousId(fstream& idSequenceFile);
		void incrementIdInFile(unsigned long int previousId, fstream& idSequenceFile);

	public:
		static const string FILE_ID_SEQUENCE_NAME;

		void init();
		unsigned long int getNextId();
};

