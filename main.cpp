#include "animal.h"
#include "DLL.h"

//Angeline Vu, 2/19/2024, CS302-001, Program 2
//This file implements the main program

//Terminates program: displays message and exits
void user_terminate()
{
	cout << "\nError. Terminating Program\n\n.";
	exit(1);
}

//Main function
int main()
{
	set_terminate(user_terminate);	//Set terminating program to mine
	char selection = main_menu();	//Get menu option

	string attribute;	//Used later to add to traits/skills

	//PET
	if (selection == '1')
	{
		DLL<pet> pet_library;			//Make DLL
		for (int i = 0; i < SIZE; ++i)		//Populate lists
		{
			pet * new_pet = new pet(pet_species[i], pet_breed[i], pet_trick[i], pet_treat[i]);
			pet_library.insert(*new_pet);
			delete new_pet;
		}

		pet temp_pet;	//Holds pet entry
		do 
		{
			selection = submenu();	//Second menu
			switch (selection)
			{
				case '1': if (!pet_library.display())	//Display library
						  cout << "\n\nEmpty Collection\n";
					  break;

				case '2': try {
						  pet_library.insert(); 	//Insert
					  }	
					  catch (...)
					  {
						  "\nInvalid Input. Unsuccessful Insertion\n";
					  }

					  break;

				case '3': break; //Quit

				case '4': try {
						  cin >> temp_pet; 	//Retrieve
						  node<pet> * hold;	//Pointer to node
						  if (pet_library.retrieve(temp_pet, hold))
							  //Display retrieved data
							  cout << "\n\nSuccessful Retrieval:\n" << hold->get_data();
						  else
							  cout << "\n\nNo Match\n";
					  }
					  catch (...)
					  {
						  "\nInvalid Input. Unsuccessful Retrieval\n";
					  }

					  break;

				case '5': try {cin >> temp_pet;	//Remove one, read in entry for removal
						  if (pet_library.rm_one(temp_pet))
							  cout << "\n\nSuccessful Removal\n";
						  else
							  cout << "\n\nNo Match\n";
					  }
					  catch (...)
					  {
						  "\nInvalid Input. Unsuccessful Removal\n";
					  }

					  break;

				default: break;	//Invalid entry
			}

		} while (selection != '3');	//Quit!
	}

	//SERVICE
	else if (selection == '2')
	{
		DLL<service> service_library;		//Make DLL
		for (int i = 0; i < SIZE; ++i)		//Populate lists
		{
			service * new_service = new service(service_species[i], service_breed[i], service_job[i], service_traits[i]);
			service_library.insert(*new_service);
			delete new_service;
		}

		service temp_service;	//Hold for service data
		do 
		{
			selection = submenu();	//Submenu
			switch (selection)
			{
				case '1': if (!service_library.display())	//Display
						  cout << "\n\nEmpty Collection\n";
					  break;

				case '2': try {		//Insert entry
						  service_library.insert();
					  }
					  catch (...)
					  {
						  "\nInvalid Input. Unsuccessful Insertion\n";
					  }
					  break;

				case '3': break;	//Quit

				case '4': try{
						  cin >> temp_service; //Retrieve
						  node<service> * hold;
						  if (service_library.retrieve(temp_service, hold))
						  {	
							  cout << "\n\nSuccessful Retrieval:\n";
							  do
							  {	
								  selection = retrieve_menu(hold->get_data());	//Display retrieval menu
								  switch (selection)
								  {
									  case '1':	//Display
										  hold->display();
										  break;
									  case '2':
										  cin >> attribute;	//Get attribute for appending
										  hold->get_data() += attribute;
										  break;
									  case '3': break;	//Quit subsubmenu
									  default: break;		//Invalid input
								  }


							  } while (selection != '3');	//Quit
							  selection = 0;		//Otherwise, entire program ends
						  }
						  else
							  cout << "\n\nNo Match\n";
					  }
					  catch (...)
					  {
						  "\nInvalid Input. Unsuccessful Retrieval\n";
					  }
					  break;


				case '5': try {cin >> temp_service; //Remove one
						  if (service_library.rm_one(temp_service))
							  cout << "\n\nSuccessful Removal\n";
						  else
							  cout << "\n\nNo Match\n";
					  }
					  catch (...)
					  {
						  "\nInvalid Input. Unsuccessful Removal\n";
					  }
					  break;

				default: break;	//Error!
			}
		} while (selection != '3');

	}

	//COMPETITIVE
	else if (selection == '3')
	{
		DLL<competitive> comp_library;		//Make DLL
		for (int i = 0; i < SIZE; ++i)		//Populate lists
		{
			competitive * new_comp = new competitive(comp_species[i], comp_breed[i], comp_sport[i], comp_skills[i]);
			comp_library.insert(*new_comp);
			delete new_comp;
		}

		competitive temp_comp;	//Temporary holder for comp
		do 
		{
			selection = submenu();	//Submenu
			switch (selection)

			{

				case '1': if (!comp_library.display()) //Display
						  cout << "\n\nEmpty Collection\n";
					  break;

				case '2': try {
						  comp_library.insert(); //Insert new entry
					  }
					  catch (...)
					  {
						  cout << "\nInvalid Input. Unsuccessful Insertion\n";
					  }
					  break;

				case '3': break;	//Quit

				case '4': try {
						  cin >> temp_comp; //Retrieve
						  node<competitive> * hold;
						  if (comp_library.retrieve(temp_comp, hold))	//Retrieve data!
						  {	
							  cout << "\n\nSuccessful Retrieval:\n";
							  do
							  {	
								  selection = retrieve_menu(hold->get_data());	//Retrieve value
								  switch (selection)
								  {
									  case '1':	//Display
										  hold->display();
										  break;
									  case '2':	//Add attribute to end of skills
										  cin >> attribute;
										  hold->get_data() += attribute;
										  break;
									  case '3': break;	//Quit
									  default: break;		//Invalid!
								  }


							  } while (selection != '3');	//Quit subsubmenu
							  selection = 0;		//Otherwise, entire program ends
						  }
						  else
							  cout << "\n\nNo Match\n";
					  }
					  catch (...)
					  {
						  "\nInvalid Input. Unsuccessful Removal\n";
					  }
					  break;

				case '5': cin >> temp_comp;	//Remove one
					  if (comp_library.rm_one(temp_comp))
						  cout << "\n\nSuccessful Removal\n";
					  else
						  cout << "\n\nNo Match\n";
					  break;

				default: break;		//Invalid entry
			}
		} while (selection != '3');	//Quit when 3
	}
	return 0;
}

//Menu
char main_menu()
{
	cout << "\n______________________________________________\n"
		"\n\t🐾A N I M A L  L I B R A R Y🐾\n"
		"______________________________________________"
		"\n______________________________________________\n\n"
		"\t ____________________________\n"
		"\t|\t\t\t     |"
		"\n\t|\tMenu\t\t     |"
		"\n\t|\t1. Pet\t\t     |\n\t|\t2. Service\t     |\n\t|\t3. Competitive\t     |\n"
		"\t|\t\t\t     |"
		"\n\t ￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n"
		"Selection: ";

	char input = ' ';
	cin >> input;

	switch (input)
	{
		case '1': 
			cout << "______________________________________________"
				"\n\n      🦴 🦴 P E T  L I B R A R Y 🦴 🦴\n"
				"______________________________________________\n\n";
			break;

		case '2': 
			cout << "______________________________________________"
				"\n\n   👷 👷 S E R V I C E  L I B R A R Y 👷 👷\n"
				"______________________________________________\n\n";
			break;

		case '3': 
			cout << "______________________________________________"
				"\n\n  🏅 C O M P E T I T I V E  L I B R A R Y 🏅\n"
				"______________________________________________\n\n";
			break;

		default: cout << "\nInvalid Selection.\n";
			 break;
	}

	return input;
}

//Menu for viewing/adding options within a library
char submenu()
{
	cout << "\t ____________________________\n"
		"\t|\t\t\t     |"
		"\n\t|\tSubmenu\t\t     |"
		"\n\t|\t1. Display\t     |\n\t|\t2. Add Entry\t     |\n\t|\t3. Quit\t\t     |"
		"\n\t|\t4. Retrieve\t     |\n\t|\t5. Remove Entry\t     |\n"
		"\t|\t\t\t     |"
		"\n\t ￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n";

	char input = ' ';
	cout << "Selection: ";
	cin >> input;
	cin.clear();
	cin.ignore(100, '\n');

	switch (input)
	{
		case '1': cout << "\nDisplay";
			  break;

		case '2': cout << "\nAdd Entry";
			  break;

		case '3': cout << "\nProgram Exited\n\n";
			  break;

		case '4': cout << "\nRetrieve Entry\n";
			  break;

		case '5': cout << "\nRemove Entry\n";
			  break;

		default: cout << "\nInvalid Selection.\n";
			 break;
	}

	return input;
}


	template <typename TYPE>
int retrieve_menu(TYPE & source)
{
	cout << "\t ____________________________\n"
		"\t|\t\t\t     |"
		"\n\t|\tRetrieve Menu\t     |"
		"\n\t|\t1. Display\t     |\n\t|\t2. Add Attribute     |\n\t|\t3. Quit\t\t     |\n"
		"\t|\t\t\t     |"
		"\n\t ￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n";

	char input = ' ';
	cout << "Selection: ";
	cin >> input;
	cin.clear();
	cin.ignore(100, '\n');

	switch (input)
	{
		case '1': cout << "\nDisplay";
			  break;

		case '2': cout << "\nAdd Attribute: ";
			  break;

		case '3': cout << "\nMenu Exited\n\n";
			  break;

		default: cout << "\nInvalid Selection.\n";
			 break;
	}

	return input;
}
