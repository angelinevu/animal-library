#include <iostream>
#include <cctype>
#include <cstring>
#include <exception>
#include <vector>
using namespace std;

//Angeline Vu, 2/19/2024, CS302-001, Program 2
//This program stores a collection of animals with respect
//to each animal's relationship to humans. The program is automatically
//populated with written entries. The client will have 2 menus to select from.
//Duplicates are NOT allowed!

//This file has class interfaces related to the animal classs 
//and prototypes for UI

//Prototypes
char main_menu();	//Asks the user for a choice between animal types
char submenu();		//Asks the user for options with collection

template <typename TYPE>
int retrieve_menu(TYPE & source);	//Asks the user for options after entry retrieval

void user_terminate();	//Extreme error, terminates program

//Global constants: will populate the list
const int SIZE = 5;	//5 items populated
const vector<string> pet_species = {"Dog", "Cat", "Snake", "Pig", "Gerbil"};	//For pets
const vector<string> pet_breed = {"Golden Retriever", "Calico", "King Snake", "Potbellied Pig", "Mongolian"};
const vector<string> pet_trick = {"Roll", "N/A", "Hiss", "Oink", "Run"};
const vector<string> pet_treat = {"Bones", "Fish", "Mice", "Apples", "Hay"};

const vector<string> service_species = {"Dog", "Dog", "Monkey", "Bird", "Horse"};	//For service animals
const vector<string> service_breed = {"Golden Retriever", "Labrador Retriever", "Capuchin", "Parrot", "Arabian"};
const vector<string> service_job = {"Emotional Support", "Emotional Support", "Emotional Support", "Emotional Support", "Travel"};
const vector<string> service_traits = {"Friendly", "Gentle", "Affectionate", "Talkative", "Speedy"};

const vector<string> comp_species = {"Dog", "Horse", "Horse", "Bull", "Cow"}; 	//For competitive animals
const vector<string> comp_breed = {"Bordie Collie", "Standardbred", "Hanoverian", "Bucking Bull", "Holstein"};
const vector<string> comp_sport = {"Flyball", "Racing", "Show Jumping", "Rodeo Events", "Livestock Competitions"};
const vector<string> comp_skills = {"Agility", "Speed, Agility", "Versatility", "Speed", "High milk production"};

//Animal base class
class animal
{
	public:
		animal();							//Default constructor
		animal(const string & a_species, const string & a_breed);	//Constructor
		animal(const animal & source);					//Copy constructor

		animal & operator=(const animal & source);			//= overloader
		bool operator>(const animal &);					//> overloader
		bool operator>=(const animal &);				//>= overloader
		bool operator<(const animal &);					//< overloader
		bool operator<=(const animal &);				//<= overloader
		bool operator==(const animal &);				//== overlaoder
		bool operator!=(const animal &);				//!= overlaoder
		friend ostream & operator<<(ostream &, const animal &);		//<< overloader
		friend istream & operator>>(istream &, animal &);		//>> overloader
		~animal();							//Destructor

	protected:
		char * species;		//Name of the animal
		string breed;		//Breed of animal
};

//Derived pet class
class pet : public animal
{
	public:
		pet();						//Default constructor
		pet(const string & species, const string & breed, const string & trick, const string & treat);	//Constructor
		pet(const pet & source);			//Copy constructor
		pet & operator=(const pet & source);		//Assignment overloader
		bool operator==(const pet &);				//== overlaoder
		bool operator!=(const pet &);				//!= overlaoder
		friend ostream & operator<<(ostream &, const pet &);	//<< overloader
		friend istream & operator>>(istream &, pet &);		//>> overloader
		~pet();							//Destructor

	protected:
		char * trick;	//Animal's favorite trick
		string treat;	//Favorite treat
};

//Dervied service class
class service : public animal
{
	public:
		service();							//Default constructor
		service(const string & species, const string & breed, const string & a_job, const string & xp);	//Constructor
		service operator+(const service &);				//+ to traits
		service & operator+=(const service &);				//+= to traits
		bool operator==(const service &);				//== overlaoder
		bool operator!=(const service &);				//!= overlaoder
		friend ostream & operator<<(ostream &, const service &);	//<< overloader
		friend istream & operator>>(istream &, service &);		//>> overloader
		friend service operator+(const string & attribute, const service & source);	//+ Overloader with string
		friend service operator+(const service & source, const string & attribute);
		friend service & operator+=(const string & attribute, service & source);	//+= Overloader with string
		friend service & operator+=(service & source, const string & attribute);	
		~service();							//Destructor

	protected:
		string job;	//Animal's occupation
		string traits;	//Traits of the job
};

//Derived competitivee class
class competitive : public animal
{
	public:
		competitive();							//Default constructor
		competitive(const string & species, const string & breed, const string & a_sport, const string & a_skills);	//Constructor
		competitive operator+(const competitive &);			//+ to skills
		competitive & operator+=(const competitive &);			//+= to skills
		bool operator==(const competitive &);				//== overlaoder
		bool operator!=(const competitive &);				//!= overlaoder
		friend ostream & operator<<(ostream &, const competitive &);	//<< overloader
		friend istream & operator>>(istream &, competitive &);		//>> overloader
		friend competitive operator+(const string & attribute, const competitive & source);	//+ Overloader with string
		friend competitive operator+(const competitive & source, const string & attribute);
		friend competitive & operator+=(const string & attribute, competitive & source);	//+= Overloader with string
		friend competitive & operator+=(competitive & source, const string & attribute);
		~competitive();							//Destructor

	protected:
		string sport;	//Animal sport played
		string skills;	//Skills related to sport
};
