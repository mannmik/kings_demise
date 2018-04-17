/*****************************************
**Author: Mike Mann
**Description: Hallway declaration.
*****************************************/

#ifndef HALLWAY_HPP
#define HALLWAY_HPP
#include "Space.hpp"
#include "KingsRoom.hpp"
#include "Character.hpp"

class Hallway : public Space
{
private:
	
	////pointers that allow player to move around the game
	Space *forward;
	Space *right;
	Space *left;
	Space *back;

public:

	Hallway() : Space("Hallway") 
	{
		forward = new KingsRoom;
		right = NULL;
		left = NULL;
		back = NULL;
	}

	~Hallway()
	{
		delete forward;
		forward = NULL;
	}

	virtual void interact();
	virtual Space* menu();

};
#endif
