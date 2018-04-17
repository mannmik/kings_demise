/*****************************************
**Author: Mike Mann
**Description: Village declaration.
*****************************************/

#ifndef VILLAGE_HPP
#define VILLAGE_HPP
#include "Space.hpp"
#include "GeneralHut.hpp"
#include "BlackSmith.hpp"
#include "Kitchen.hpp"
#include "Character.hpp"

class Village : public Space
{
private:
	//pointers that allow player to move around the game
	Space *forward;
	Space *right;
	Space *left;
	Space *back;

public:
	Village() : Space("Village") 
	{
		forward = NULL;
		right = new BlackSmith;
		left = new Kitchen;
		back = NULL;
	}

	~Village()
	{
		delete right;
		right = NULL;
		delete left;
		left = NULL;
	}

	virtual void interact();
	virtual Space* menu();

};
#endif
