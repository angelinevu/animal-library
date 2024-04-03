#include "animal.h"

//Angeline Vu, 2/19/2024, CS302-001, Program 2
//This file implements the animal and related class
//methods

//Animal class
//Default constructor: sets values to 0 equivalent
animal::animal() : species(nullptr), breed("") {}

//Constructor: initializes object with a species and a breed
animal::animal(const string & a_species, const string & a_breed) : species(nullptr), breed(a_breed)
{
//	string copy = a_species;
//	for (int i = 0; i < copy.length(); ++i)
//		copy[i] = toupper(copy[i]);

	if (species)
		delete [] species;
	species = new char[strlen(a_species.c_str()) + 1];
	strcpy(species, a_species.c_str());
}

//Copy constructor: initializes obj with value of same type obj
animal::animal(const animal & source) : species(nullptr), breed(source.breed)
{
	if (species)
		delete [] species;
	species = new char[strlen(source.species) + 1];
	strcpy(species, source.species);
}

//Assignment overloader: = functionality
animal & animal::operator=(const animal & source)
{
	if (this == &source)	//Self assignment
		return *this;

	if (species)		//Delete if exists
		delete [] species;

	species = new char[strlen(source.species) + 1];	//New 
	strcpy(species, source.species);

	breed = source.breed;	//Copy breed

	return *this;
}

//> Overloader, sort by species first; if match, sort by breed
bool animal::operator>(const animal & source)
{
	int result = strcmp(species, source.species);

	if (result < 0)	//Compare species
		return true;

	if (!result)	//Same species
		if (breed < source.breed)
			return true;
		
	return false;
}

//>= Overloader: allows comparison >=
bool animal::operator>=(const animal & source)
{
	return !(*this < source);	//Opposite of <
}

//< Overloader: allows comparison <
bool animal::operator<(const animal & source)
{
	int result = strcmp(species, source.species);

	if (result > 0)	//Compare species
		return true;

	if (!result)	//Species match
		if (breed > source.breed)
			return true;

	return false;
}

//<= Overloader: allows comparison >=
bool animal::operator<=(const animal & source)
{
	return !(*this > source);	//Opposite of >
}

//== Overloader: allows == comparison
bool animal::operator==(const animal & source)
{
	if (!strcmp(species, source.species) && breed == source.breed)
		return true;

	return false;
}

//!= Overloader: allows != comparison
bool animal::operator!=(const animal & source)
{
	return !(*this == source);
}

//Destructor: deletes any dynamic memory and sets
//species and breed to 0 equivalent value
animal::~animal()
{
	if (species)
		delete [] species;
	species = nullptr;
	breed = "";
}

//Pet class
//Default constructor: sets fields to 0
pet::pet() : trick(nullptr), treat("") {}

//Constructor: sets species, breed, trick, and treat
pet::pet(const string & species, const string & breed, const string & a_trick, const string & a_treat) \
		: animal(species, breed), trick(nullptr), treat(a_treat)
{
	if (trick)
		delete [] trick;
	trick = new char[strlen(a_trick.c_str()) + 1];
	strcpy(trick, a_trick.c_str());
}

//Copy constructor: initializes with value of another obj of same class
pet::pet(const pet & source) : animal(source), trick(nullptr), treat(source.treat)
{
	if (trick)
		delete [] trick;
	trick = new char[strlen(source.trick) + 1];
	strcpy(trick, source.trick);
}

//Assignment overloader: deep copy
pet & pet::operator=(const pet & source)
{
	if (this == &source)	//Check for self assignment
		return *this;

	animal::operator=(source);	//Copy parent

	if (trick)			//Does trick exist alr? Then del
		delete [] trick;

	trick = new char[strlen(source.trick) + 1];
	strcpy(trick, source.trick);

	treat = source.treat;	//Copy treat

	return *this;
}

//== Overloader: check for equality
bool pet::operator==(const pet & source)
{
	if (animal::operator!=(source))	//Species and breed are not equal
		return false;
	if (!strcmp(trick, source.trick) && source.treat == treat)	//Trick and treat are the same
		return true;	
	return false;
}

//!= Overloader: check for not equal to
bool pet::operator!=(const pet & source)
{
	return !(*this == source);	//Opposite of ==
}

//Destructor: deletes dynamic memory
//Sets everything to 0 equivalent
pet::~pet()
{
	if (trick)
		delete [] trick;
	trick = nullptr;
	treat = "";
}

//Service class
//Default constructor: sets everything to 0 equivalent
service::service() : job(""), traits("") {}

//Constructor: sets species, breed, job, and traits
service::service(const string & species, const string & breed, const string & a_job, const string & trait) \
		: animal(species, breed), job(a_job), traits(trait) {}

//+ overloader, allows use of +
service service::operator+(const service & source)
{
	return service(species, breed, job, traits + ", " + source.traits);
}

//+= overloader, allows use of += in adding new traits
service & service::operator+=(const service & source)
{
	traits = traits + ", " + source.traits;
	return *this;
}

//== Overloader: check for equality
bool service::operator==(const service & source)
{
	if (animal::operator!=(source))	//Species and breed are not equal
		return false;
	if (job == source.job && source.traits == traits)	//Job and traits are equal
		return true;	
	return false;
}

//!= Overloader: check for not equal to
bool service::operator!=(const service & source)
{
	return !(*this == source);	//Opposite of ==
}

//Destructor: sets fields to 0 equivalent
service::~service()
{
	job = traits = "";
}

//Competitive class
//Default constructor
competitive::competitive() : sport(""), skills("") {}

//Constructor: sets species, breed, sport, and skills
competitive::competitive(const string & species, const string & breed, const string & a_sport, const string & a_skills) \
		: animal(species, breed), sport(a_sport), skills(a_skills) {}

//+ overloader: allows use of + in adding new skills
competitive competitive::operator+(const competitive & source)
{
	return competitive(species, breed, sport, skills + ", " + source.skills);
}

//+= overloader: lvalue version of +
competitive & competitive::operator+=(const competitive & source)
{
	skills = skills + ", " + source.skills;
	return *this;
}

//== Overloader: check for equality
bool competitive::operator==(const competitive & source)
{
	if (animal::operator!=(source))	//Species and breed are not equal
		return false;
	if (sport == source.sport && source.skills == skills)	//Job and traits are equal
		return true;	
	return false;
}

//!= Overloader: check for not equal to
bool competitive::operator!=(const competitive & source)
{
	return !(*this == source);	//Opposite of ==
}

//Destructor: sets fields to 0 equivalent
competitive::~competitive()
{
	sport = skills = "";
}
