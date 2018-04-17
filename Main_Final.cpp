/*****************************************
**Author: Mike Mann
**Description: Main file
*****************************************/

#include "Space.hpp"
#include "Village.hpp"
#include "Character.hpp"
using namespace std;

int main()
{
	int choice;
	
	//introduction and instructions for beating the game
	cout << "\n\nWelcome to A King's Demise! In this game you are living through Altair; a former assassin from medieval times.\n";
	cout << "To win the game use the dagger, key, general's note, and the wine to assassinate the king quietly.\n";
	cout << "Move to the BlackSmith, then the General's Hut, then to the Kitchen, Hallway, and King's Room.\n";

	//create new character and village space as starting points of the game
	Character *c = new Character;
	Village *v = new Village;

	//sets the character's current location and sets village's character to character in main
	c->setCurrentLocation(v);
	v->setCharacter(c);

	cout << "\nEnter 1: To begin the game.\nEnter 2: To quit.\n";
	while (!(cin >> choice) || choice < 1 || choice > 2)
	{
		cin.clear();
		cin.ignore();
		cout << "Enter 1: To begin the game.\nEnter 2: To quit.\n";
	}

	if (choice == 1) 
	{
		//loop takes the player through the game
		while (c->getSuccess() == false && c->getFailure() == false)
		{

			//calls the interact function of the current location the character is in
			c->getCurrent()->interact();

			//check the bools to see if the character should move further in the game
			if (c->getSuccess() == false && c->getFailure() == false)
				c->setCurrentLocation(c->getCurrent()->menu());
		}
	}
	
	//deallocating village space and character
	delete v;
	v = NULL;
	delete c;
	c = NULL;
	
	return 0;
}
