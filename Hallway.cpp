/*****************************************
**Author: Mike Mann
**Description: Hallway implementation.
*****************************************/

#include "Hallway.hpp"
#include <iostream>
using namespace std;

void Hallway::interact()
{
	int choice;
	bool validate = false;

	cout << "\nThere are 2 soldiers on guard outside of the King's room!\n";
	cout << "Guards: \"What is your business here!?\"\n";
	
	while (!validate)
	{
		cout << "\nEnter 1: To give them the letter from the general.\n";
		cout << "Enter 2: To tell them you are bringing the King some wine.\n";
		cout << "Enter 3: To try and eliminate them with force!\n";
		while (!(cin >> choice) || choice < 1 || choice > 3)
		{
			cin.clear();
			cin.ignore();
			cout << "\nThere are 2 soldiers on guard outside of the King's room!\n";
			cout << "Guards: \"What is your business here!?\"\n";
			cout << "\nEnter 1: To give them the letter from the general.\n";
			cout << "Enter 2: To tell them you are bringing the King some wine.\n";
			cout << "Enter 3: To try and eliminate them with force!\n";
		}

		if (choice == 1)
		{
			if (c->getLetter())
			{
				validate = true;
				cout << "You: \"I was sent here to give you these orders from your general.\"\n";
				cout << "Guards: \"We have been ordered to report at camp CliffSide outside of the village!\"\n";
				cout << "The guards have left!\n";
				cout << "Great Job! The king's room is locked, so try the master key you found earlier.\n";
				cout << "\nEnter 1: To use the master key on the King's door.\n";
				while (!(cin >> choice) || choice > 1 || choice < 1)
				{
					cin.clear();
					cin.ignore();
					cout << "\nEnter 1: To use the master key on the King's door.\n";
				}

				if (choice == 1)
				{
					cout << "The key worked again! The King's room is now unlocked. The plan is coming together!\n";
				}
			}
			else
			{
				cout << "Uh-oh you don't have the letter! Try another option.\n";
			}
		}

		else if (choice == 2)
		{
			if (c->getWine())
			{
				validate = true;
				cout << "You: \"I was sent to bring the King some more wine.\"\n";
				cout << "The guards are opening the door for you!\n";
			}
			else
				cout << "You don't have any wine! Try another option.\n";
		}

		else if (choice == 3)
		{
			validate = true;
			cout << "You have lunged at the first guard at stole his sword, but all the noise has attracted other guards!\n";
			cout << "You were unable to over power the guards! They have captured you and sent you to the stocks.\n";
			cout << "Next time try to be more stealthy.\n";
			c->setFailure(1);
		}
	}
}

Space* Hallway::menu()
{
	bool validate = false;
	int choice;

	cout << "Enter 1: To move forward and enter the King's Chambers.\n";
	while (!(cin >> choice) || choice < 1 || choice > 1)
	{
		cin.clear();
		cin.ignore();
		cout << "Enter 1: To move forward and enter the King's Chambers.\n";
	}
		
	if (choice == 1)
	{
		forward->setCharacter(this->c);
		return forward;
	}
}