#include <string>

using namespace std;

class Animal {

	private:
		string name;
		int age;
		string type;
		string breed;

	public:
		void setName(string name) {
			name = name;
		}

		string getName() {
			return name;
		}

		void setAge(int age) {
			age = age;
		}

		int getAge() {
			return age;
		}

		void setType(string type) {
			type = type;
		}

		string getType() {
			return type;
		}

		void setBreed(string breed) {
			breed = breed;
		}

		string getBreed() {
			return breed;
		}
};
