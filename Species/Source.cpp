#include <iostream>;
#include <vector>;
#include <string>;
#include <random>;
#include <ctime>;
#include <iomanip>;

using namespace std;

static default_random_engine generator(time(NULL));
uniform_int_distribution<int> nameGenF(1, 4);
uniform_int_distribution<int> nameGenL(1, 5);
uniform_int_distribution<int> morphGen(1, 4);
uniform_real_distribution<double> heightGen(3.0, 8.0);
uniform_int_distribution<int> soundGen(1, 3);

vector<string> namepoolF{ "Car","Ny","Op","Lag" };
vector<string> namepoolL{ "inox","sine","lucid","octa","ulin" };

vector<string> soundpoolS{ "Bark", "Honk", "Meow" };

string namepool1();
string namepool2();
string soundpool();

void print_all_names();

class Species {
public:

	string name = "NONAME";
	string morphology = "DEFAULT";
	double height = 0.00;
	string sound = "NOSOUND";

	void setMorph() {
		int temp = morphGen(generator);
		switch (temp) {
		case 1: morphology = "Canidae"; break;
		case 2: morphology = "Cervidae"; break;
		case 3: morphology = "Primate"; break;
		case 4: morphology = "Mustilidae"; break;
		default: morphology = "DEFAULT";
		}
	}

	void setName() {
		name = namepool1() + namepool2();
	}

	void setHeight() {
		height = heightGen(generator);
	}

	void setSound() {
		sound = soundpool();
	}
};

int main()
{
	vector<Species> list_of_species;
	int i = 0;



	while (i++ < 10) {
		Species* s = new Species;
		s->setMorph();
		s->setName();
		s->setHeight();
		s->setSound();

		cout << s->name << " Morphology: " << s->morphology << "---------- Height is: " << setprecision(2) << s->height << " Sound is: " << s->sound << endl;

		list_of_species.push_back(*s);
	}

	cout << "\n\n\n\n";

	cout << list_of_species[2].name << " Morphology: " << list_of_species[2].morphology;
	cout << "\n\n\n\n\n\n";

	print_all_names();

	return 0;
}

//name pool
string namepool1() {
	return namepoolF[nameGenF(generator) - 1];
}

string namepool2() {
	return namepoolL[nameGenL(generator) - 1];
}

string soundpool() {
	return soundpoolS[soundGen(generator) - 1];
}

void print_all_names() {
	for (auto names : namepoolF) {
		for (auto names2 : namepoolL) {
			cout << names << names2 << endl;
		}
	}
}