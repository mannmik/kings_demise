/*****************************************
**Author: Mike Mann
**Description: KingsRoom declaration.
*****************************************/

#ifndef KINGSROOM_HPP
#define KINGSROOM_HPP
#include "Space.hpp"
#include "Character.hpp"

class KingsRoom : public Space
{
private:
	
	//pointers that allow player to move around the game
	Space *forward;
	Space *left;
	Space *right;
	Space *back;

public:

	KingsRoom() : Space("King's Chambers") 
	{ 
		forward = NULL;
		left = NULL;
		right = NULL;
		back = NULL;
	}

	virtual void interact();
	virtual Space* menu();

};
#endif
