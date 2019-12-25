#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class IdSequence {
	private:
		static unsigned long int getPreviousId(fstream& idSequenceFile);
		static void incrementIdInFile(unsigned long int previousId, fstream& idSequenceFile);

	public:
		static const string FILE_ID_SEQUENCE_NAME;

		static void init();
		static unsigned long int getNextId();
};

