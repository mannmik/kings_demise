/*****************************************
**Author: Mike Mann
**Description: KingsRoom implementation.
*****************************************/

#include "KingsRoom.hpp"
#include <iostream>
using namespace std;

void KingsRoom::interact()
{
	int choice;

	cout << "\nYou are now in the King's room!\n";
	cout << "\nKing: Who are you and what are you doing in my room?\n";
	cout << "\nEnter 1: To tell the King you have brought him wine.\n";
	cout << "Enter 2: To try to assassinate the king now!\n";
	while (!(cin >> choice) || choice > 2 || choice < 1)
	{
		cin.clear();
		cin.ignore();
		cout << "\nEnter 1: To tell the King you have brought him wine.\n";
		cout << "Enter 2: To try to assassinate the king now!\n";
	}

	if (choice == 1)
	{
		cout << "King: Well ok then, come and pour me a glass and sit down!\n";
		cout << "Enter 1: To pour the King some wine.\n";
		while (!(cin >> choice) || choice > 1 || choice < 1)
		{
			cin.clear();
			cin.ignore();
			cout << "Enter 1: To pour the King some wine.\n";
		}

		if (choice == 1)
		{
			cout << "You have poured the King some wine and are now listening to him rant about the villagers.\n";
			cout << "You have listened to the King go on and he has now finished off all the wine. Now is a good time to strike!\n";
			cout << "\nEnter 1: To assassinate the King!\n";
			while (!(cin >> choice) || choice > 1 || choice < 1)
			{
				cin.clear();
				cin.ignore();
				cout << "\nEnter 1: To assassinate the King!\n";
			}

			if (choice == 1)
			{
				if (c->getDagger())
				{
					cout << "Use your dagger to make the assassination quick and easy!\n";
					cout << "\nEnter 1: To assassinate the King with the dagger!\n";
					while (!(cin >> choice) || choice > 1 || choice < 1)
					{
						cin.clear();
						cin.ignore();
						cout << "\nEnter 1: To assassinate the King!\n";
					}

					if (choice == 1)
					{
						cout << "You have done it! The mad King is now gone! All of the villagers are rejoicing!\n";
						c->setSuccess(1);
					}
				}
				else if (c->getDagger() == false)
				{
					cout << "Oh no you don't have the dagger! The king is putting up a fight!\n";
					cout << "You have wounded the king, but all of the noise attracted attention and you have been caught!\n";
					c->setFailure(1);
				}
			}
		}
	}

	else if (choice == 2)
	{
		if (c->getDagger())
		{
			cout << "Use your dagger to assassinate the king!\n";
			cout << "\nEnter 1: To use your dagger on the King!\n";
			while (!(cin >> choice) || choice > 1 || choice < 1)
			{
				cin.clear();
				cin.ignore();
				cout << "\nEnter 1: To use your dagger on the King!\n";
			}

			if (choice == 1)
			{
				cout << "The King is strong and resisting!\n";
				cout << "You have managed to assassinate the King, but the struggle made too much noise and you were captured!\n";
				c->setFailure(1);
			}
		}

	}
}

Space* KingsRoom::menu()
{
	return NULL;
}
