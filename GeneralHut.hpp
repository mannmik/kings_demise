/*****************************************
**Author: Mike Mann
**Description: GeneralHut declaration.
*****************************************/

#ifndef GENERALHUT_HPP
#define GENERALHUT_HPP
#include "Space.hpp"
#include "Character.hpp"
#include "Kitchen.hpp"

class GeneralHut : public Space
{
private:
	//bool tracking if the player picked up this space's item
	bool gotNote;

	//pointers that allow player to move around the game
	Space *forward;
	Space *back;
	Space *left;
	Space *right;

public:

	GeneralHut() : Space("General's Hut") 
	{
		gotNote = false;
		forward = NULL;
		left = new Kitchen;
		right = NULL;
		back = NULL;
	}

	~GeneralHut()
	{
		delete forward;
		forward = NULL;
	}
	virtual void interact();
	virtual Space* menu();
};
#endif
