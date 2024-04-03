#include "animal.h"

//Angeline Vu, 2/19/2024, CS302-001, Program 2
//This program implements all friend functions
//This includes << >> + +=

//Animal friends
//<< Overloader. Displays animal fields source and breed with the << operator
ostream & operator<<(ostream &, const animal & source)
{
	if (!source.species || source.breed == "")	//Cannot display nothing
		throw;

	return cout << "Species: " << source.species << "\nBreed: " << source.breed << endl;
}

//>> Overloader. Takes input for animal fields source and breed with the >> operator
istream & operator>>(istream & cin, animal & source)
{
	string species;		//Temporary string
	cout << "\nSpecies: ";
	getline(cin >> ws, species);

	//for (int i = 0; i < species.length(); ++i)	//Upper case!
	//	species[i] = toupper(species[i]);

	if (source.species)		//Species exists? Delete
		delete [] source.species;

	source.species = new char[strlen(species.c_str()) + 1];		//Store as c_string
	strcpy(source.species, species.c_str());

	cout << "Breed: ";		//Get breed
	getline(cin >> ws, source.breed);

	if (!strcmp(source.species, "") || source.breed == "")	//Empty fields
		throw;

	return cin;
}

//Pet friends
//<< Overloader. Displays pet fields trick and treat. Also displays fields animal and breed
ostream & operator<<(ostream & cout, const pet & source)
{
	cout << static_cast<animal>(source);	//Display parent fields

	if (!source.trick || source.treat == "")
		throw;

	return cout << "Favorite Trick: " << source.trick << "\nFavorite Treat: " << source.treat << "\n\n";
}

//>> Overloader. Reads in species, breed, trick, and treat from user with >> operator
istream & operator>>(istream & cin, pet & source)
{
	cin >> static_cast<animal&>(source);	//Read in parent fields

	string trick;		//Get temporary trick
	cout << "Favorite Trick: ";
	getline(cin >> ws, trick);

	if (source.trick)	//If exists, delete
		delete [] source.trick;

	source.trick = new char[strlen(trick.c_str()) + 1];	//Create array
	strcpy(source.trick, trick.c_str());

	cout << "Favorite Treat: ";		//Get treat
	getline(cin >> ws, source.treat);

	if (!strcmp(source.trick, "") || source.treat == "")	//Empty fields
		throw;


	return cin;
}	

//Service friends
//<< Overloader. Displays breed, species, job, and traits of a service animal
ostream & operator<<(ostream & cout, const service & source)
{
	cout << static_cast<animal>(source);	//Display parent fields

	if (source.job == "" || source.traits == "")
		throw;

	return cout << "Job: " << source.job << "\nTraits: " << source.traits << "\n\n";
}

//>> Overloader. Reads in species, breed, job, traits with >> operator
istream & operator>>(istream & cin, service & source)
{
	cin >> static_cast<animal&>(source);	//Get parent fields
	cout << "Job: ";
	getline(cin >> ws, source.job);		//Get job
	cout << "Traits: ";
	getline(cin >> ws, source.traits);	//Get traits

	if (source.job == "" || source.traits == "")	//Empty fields
		throw;

	return cin;
}

//+ overloader with string arg!
service operator+(const string & attribute, const service & source)
{
	return service(source.species, source.breed, source.job, source.traits + ", " + attribute);
}

//+ overloader with string arg!
service operator+(const service & source, const string & attribute)
{
	return service(source.species, source.breed, source.job, source.traits + ", " + attribute);
}

//+= Overloader with string Arg!
service & operator+=(const string & attribute, service & source)
{
	source.traits = source.traits + ", " + attribute;
	return source;
}

//+= Overloader with string Arg!
service & operator+=(service & source, const string & attribute)
{
	source.traits = source.traits + ", " + attribute;
	return source;
}

//Competitive friends
//<< Overloader. Displays species, breed, sport, and skills with << operator.
ostream & operator<<(ostream & cout, const competitive & source)
{
	cout << static_cast<animal>(source);	//Get parent fields

	if (source.sport == "" || source.skills == "")
		throw;

	return cout << "Sport: " << source.sport << "\nSkills: " << source.skills << "\n\n";
}

//>> Overloader. Read in breed, species, sport, skills with >> operator.
istream & operator>>(istream & cin, competitive & source)
{
	cin >> static_cast<animal&>(source);	//Read in breed and species
	cout << "Sport: ";
	getline(cin >> ws, source.sport);	//Get sport
	cout << "Skills: ";
	getline(cin >> ws, source.skills);	//Get skills

	if (source.sport == "" || source.skills == "")	//Empty fields
		throw;

	return cin;
}

//+ overloader with string arg!
competitive operator+(const string & attribute, const competitive & source)
{
	return competitive(source.species, source.breed, source.sport, source.skills + ", " + attribute);
}

//+ overloader with string arg!
competitive operator+(const competitive & source, const string & attribute)
{
	return competitive(source.species, source.breed, source.sport, source.skills + ", " + attribute);
}

//+= Overloader with string Arg!
competitive & operator+=(const string & attribute, competitive & source)
{
	source.skills = source.skills + ", " + attribute;
	return source;
}

//+= Overloader with string Arg!
competitive & operator+=(competitive & source, const string & attribute)
{
	source.skills = source.skills + ", " + attribute;
	return source;
}
