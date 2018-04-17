/*****************************************
**Author: Mike Mann
**Description: GeneralHut implementation.
*****************************************/

#include "GeneralHut.hpp"
#include <iostream>
using namespace std;

/*Funciton allows the player to interact with the space*/
void GeneralHut::interact()
{
	int choice;
	c->setCurrentLocation(this);

	cout << "\nGeneral: \"Hello you must be Altair. Did the others tell you about me?\"\n";
	cout << "You: \"Only that I should come see you. Why would a former general be involved in this?\"\n";
	cout << "General: \"I was once head of the King's Guard, but when I opposed " <<
		"his current actions he relieved me of my duties and banished me from the castle.\"\n";
	cout << "General:\"I have a note for you to take with you, but I will need you to write it beacuse the king took my right hand.\"\n";
	cout << "\nEnter 1: To write the note.\nEnter 2: To continue without the note.\n";
	while (!(cin >> choice) || choice > 2 || choice < 1)
	{
		cin.clear();
		cin.ignore();
		cout << "\nEnter 1: To write the note.\nEnter 2: To continue without the note.\n";
	}

	if (choice == 1)
	{
		cout << "The note has been written! It is false orders for King's guard to report outside of the village. This could come in handy.\n";
		cout << "\nEnter 1: To put the note in your container.\n";
		while (!(cin >> choice) || choice > 1 || choice < 1)
		{
			cin.clear();
			cin.ignore();
			cout << "\nEnter 1: To put the note in your container.\n";
		}

		if (choice == 1)
		{
			c->addItem("note");
			c->setLetter(1);
			gotNote = true;
			cout << "The Note is now in your container!\n";
			cout << "Your current container items are: \n";
			c->printC();
		}
	}

}

Space* GeneralHut::menu()
{
	bool validate = false;
	int choice;
		
	while (!validate)
		{
			cout << "Enter 1: To move left and enter the castle through the kitchen.\n";
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

	if (choice == 1)
	{
		left->setCharacter(this->c);
		//left->interact();
		return left;
	}

}
