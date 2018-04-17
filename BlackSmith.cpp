/*****************************************
**Author: Mike Mann
**Description: BlackSmith Implementation.
*****************************************/

#include "BlackSmith.hpp"
#include <iostream>
using namespace std;

void BlackSmith::interact()
{
	int choice;

	//sets the characters new current location
	c->setCurrentLocation(this);

	cout << "\nBlacksmith: \"Hello, are you Altair?\"" << endl;
	cout << "You: \"Yes, a woman came to me and said to speak with you.\" \n";
	cout << "Blacksmith: \"I have left something for you underneath that bearskin rug by the fire pit.\"\n";
	cout << "\"Please put out the fire before you leave.\"\n";
	cout << "\nThe Blacksmith has left.\n";
	cout << "\nEnter: 1 to look under the rug.\nEnter 2: To not look under the rug and leave.\n";
	while (!(cin>>choice) || choice < 1 || choice > 2)
	{
		cin.clear();
		cin.ignore();
		cout << "\nEnter: 1 to look under the rug.\nEnter 2: To not look under the rug and leave.\n";
	}

	if (choice == 1)
	{
		cout << "There is a custom forged dagger under the bear skin rug!\n";
		cout << "Do you wish to take it with you?\n";
		cout << "Enter 1: Yes.\nEnter 2: No.\n";
		while (!(cin >> choice) || choice < 1 || choice > 2)
		{
			cin.clear();
			cin.ignore();
			cout << "Enter 1: Yes.\nEnter 2: No.\n";
		}

		if (choice == 1)
		{
			bool gotDagger = true;
			c->addItem("dagger");
			c->setDagger(1);
			cout << "You have placed the dagger in your container!\n";
			cout << "Your container now has the following items:\n";
			c->printC();
		}

		cout << "It is time to leave. Remember to put out the fire!\n";
		cout << "Enter 1: To put out the fire\n";
		while (!(cin >> choice) || choice < 1 || choice > 1)
		{
			cin.clear();
			cin.ignore();
			cout << "Enter 1: To put out the fire\n";
		}
		if (choice == 1)
		{
			cout << "The fire has been put out!\n";
		}

	}

	else if (choice == 2)
	{
		cout << "Remember to put out the fire!\n";
		cout << "Enter 1: To put out the fire\n";
		while (!(cin >> choice) || choice < 1 || choice > 1)
		{
			cin.clear();
			cin.ignore();
			cout << "Enter 1: To put out the fire\n";
		}

		if (choice == 1)
			cout << "The fire is out!\n";
	}
}

Space* BlackSmith::menu()
{
	bool validate = false;
	int choice;

	do {
		while (!validate)
		{
			cout << "Enter 1: To move forward to the General's Hut.\n";
			cout << "Enter 2: To move left and enter the castle through the kitchen.\n";
			if (cin >> choice)
			{
				validate = true;
			}

			else
			{
				cin.clear();
				cin.ignore();
				cout << "\nInvalid input.\n";
			}
		}

		validate = false;

		if (choice == 1)
		{
			validate = true;
			forward->setCharacter(this->c);
			//forward->interact();
			return forward;
		}

		else if (choice == 2)
		{
			validate = true;
			left->setCharacter(this->c);
			//left->interact();
			return left;
		}
	} while (!validate);

}
