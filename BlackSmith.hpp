/*****************************************
**Author: Mike Mann
**Description: BlackSmith declaration.
*****************************************/

#ifndef BLACKSMITH_HPP
#define BLACKSMITH_HPP
#include "Space.hpp"
#include "Character.hpp"
#include "GeneralHut.hpp"
#include "Kitchen.hpp"

class BlackSmith : public Space
{
private:
	//bools tracking if items were taken by the player
	bool gotDagger;

	//pointers to other spaces in the game
	Space *forward;
	Space *right;
	Space *left;
	Space *back;

public:

	BlackSmith() : Space("Blacksmith's") 
	{
		gotDagger = false;
		forward = new GeneralHut;
		left = new Kitchen;
		right = NULL;
		back = NULL;
	}

	~BlackSmith()
	{
		delete forward;
		forward = NULL;
		delete left;
		left = NULL;
	}

	virtual void interact();
	virtual Space* menu();

};
#endif
