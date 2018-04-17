/*****************************************
**Author: Mike Mann
**Description: Village implementation.
*****************************************/

#include "Village.hpp"
#include <iostream>
using namespace std;

/*Function allow the player to interact with the space and characters in the space.*/
void Village::interact()
{
	//helps validate information gathered from the player
	bool validate = false;
	int choice;

	cout << "A woman has come to your village home to speak with you.\n";
	cout << "Woman: \"The mad King has raised taxes and he is executing those who cannot pay. I know of your past. Will you help us with the mad King?\"" << endl;
	while (validate == false)
	{
		cout << "\nEnter 1: To help the villagers.\nEnter 2: To decline.\n";
		if (cin >> choice)
		{
			validate = true;
		}
		else
		{
			cin.clear();
			cin.ignore();
			cout << "\nInvalid choice." << endl;
		}

	}

	if (choice == 1)
	{
		cout << "\n\"Woman: Great. The King has grown paranoid and never leaves his room. I have arranged for you to enter in the castle through the kitchen.\"\n";
		cout << "\"The village Blacksmith and retired General have agreed to help as well. I suggest you go see them. I will be fleeing the vilage until word of your success.\"\n";
		
		cout << "\nThe woman has now fled and gone into hiding! You will not be able to speak with her again.\n";
	}

	else if (choice == 2)
	{
		cout << "\nThe mad King has slaughtered most of the villagers and those left have fleed.\n";
		c->setFailure(1);
	}
}

/*Function helps the user move the next space by giving them a menu of options*/
Space* Village::menu()
{
	//variables help validate player input
	bool validate = false;
	int choice;
	
	//gathers user choice on where they want to move to next.
	cout << "Enter 1: To move right and visit the Black Smith.\n";
	cout << "Enter 2: To move left and enter the castle through the kitchen.\n";
	while (!(cin >> choice) || choice < 1 || choice > 2)
	{
		cin.clear();
		cin.ignore();
		cout << "Enter 1: To move right and visit the Black Smith.\n";
		cout << "Enter 2: To move left and enter the castle through the kitchen.\n";
	}

		if (choice == 1)
		{
			right->setCharacter(this->c);
			return right;
		}

		else if (choice == 2)
		{
			left->setCharacter(this->c);
			return left;
		}
	
}
