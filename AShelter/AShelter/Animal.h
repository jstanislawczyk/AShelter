#include <string>

using namespace std;

class Animal {

	private:
		unsigned long int id;
		string name;
		int age;
		string type;
		string breed;

	public:
		Animal();

		unsigned long int getId() const;
		string getName() const;
		int getAge() const;
		string getType() const;
		string getBreed() const;

		void setId(unsigned long int id);
		void setName(string name);
		void setAge(int age);
		void setType(string type);
		void setBreed(string breed);
};
