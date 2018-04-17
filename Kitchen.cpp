/*****************************************
**Author: Mike Mann
**Description: Kitchen implementation.
*****************************************/

#include "Kitchen.hpp"
#include <iostream>
using namespace std;

/*Function holds the information for the player to interact with the space*/
void Kitchen::interact()
{
	bool validate = false;
	int choice;
	
	//sets the character's current location
	c->setCurrentLocation(this);

	cout << "The door to the kitchen is locked, but there is a marked rock on the ground.\n";
	while(!gotKey)
	{
	cout << "Enter 1: To look under the rock.\nEnter 2: To try and open the door.\n";
	while (!(cin >> choice) || choice < 1 || choice > 2)
	{
		cin.clear();
		cin.ignore();
		cout << "Enter 1: To look under the rock.\nEnter 2: To try and open the door.\n";
	}

		if (choice == 1)
		{
			
			cout << "There is a key under the rock! Take the key with you.\n";
			cout << "\nEnter 1: To take the key with you.\n";
			while (!(cin >> choice) || choice < 1 || choice > 1)
			{
				cin.clear();
				cin.ignore();
				cout << "\nEnter 1: To take the key with you\n";
			}

			//add the key to the character's container and set the corresponding bools. then print items in container
			if (choice == 1)
			{
				gotKey = true;
				c->addItem("key");
				c->setKey(1);
				cout << "The key was added to your container!\n";
				cout << "Your container now has the following items: \n";
				c->printC();
			}

		}

		else if (choice == 2)
		{
			cout << "The door is locked! I would look under the rock!\n";
		}
	}

	choice = 0;
	cout << "\nEnter 1: To see if the key opens up the door.\n";
	while (!(cin >> choice) || choice < 1 || choice > 1)
	{
		cin.clear();
		cin.ignore();
		cout << "\nEnter 1: To see if the key opens up the door.\n";
	}

	if (choice == 1)
	{
		cout << "It worked! The door opened!.\n";
		cout << "There is no one in the kitchen, but there is a couple of empty flasks and a pitcher of wine.\n";
		cout << "Pour the wine into the flasks.\n";
		cout << "\nEnter 1: To pour the wine in the flasks.\n";
		while (!(cin >> choice) || choice < 1 || choice > 1)
		{
			cin.clear();
			cin.ignore();
			cout << "\nEnter 1: To see if the key opens up the door.\n";
		}
		cout << "Great the pitcher is now empty!\n";
		cout << "It may be a good idea to take the wine with you.\n" <<
			"\nEnter 1: To put the wine in your container.\nEnter 2: To leave the wine.\n";
		while (!(cin >> choice) || choice < 1 || choice > 2)
		{
			cin.clear();
			cin.ignore();
			cout << "\nEnter 1: To put the wine in your container.\nEnter 2: To leave the wine.\n";
		}

		if (choice == 1)
		{
			c->addItem("wine");
			c->setWine(1);
			gotWine = true;
			cout << "The wine was added to your container!\n" <<
				"Your container now has the following items: \n";
			c->printC();
		}
	}
}

Space* Kitchen::menu()
{
	bool validate = false;
	int choice;

		cout << "Enter 1: To move forward to the royal hallway.\n";
		while (!(cin >> choice) || choice > 1 || choice < 1)
		{
			cin.clear();
			cin.ignore();
			cout << "Enter 1: To move forward to the royal hallway.\n";
		}

		if (choice == 1)
		{
			forward->setCharacter(this->c);
			return forward;
		}
}