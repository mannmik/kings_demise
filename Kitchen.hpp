/*****************************************
**Author: Mike Mann
**Description: Kitchen declaration.
*****************************************/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP
#include "Space.hpp"
#include "Hallway.hpp"
#include "Character.hpp"

class Kitchen : public Space
{
private:
	//bool tracking if the player picked the items in this space
	bool gotWine;
	bool gotKey;
	
	//pointers that allow player to move around the game
	Space *forward;
	Space *back;
	Space *left;
	Space *right;
	
public:
	Kitchen() : Space("Kitchen") 
	{
		gotWine = false;
		gotKey = false;
		forward = new Hallway;
		back = NULL;
		left = NULL;
		right = NULL;
	}

	~Kitchen()
	{
		delete forward;
		forward = NULL;
	}

	virtual void interact();
	virtual Space* menu();

};
#endif