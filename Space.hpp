/*****************************************
**Author: Mike Mann
**Description: Space declaration.
*****************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
class Character;

class Space
{
protected:
	std::string name;
	Character *c = NULL;


public:
	Space(std::string name)
	{
		this->name = name;
		
	}

	Character* getCharacter()
	{
		return c;
	}

	std::string getName()
	{
		return name;
	}

	void setCharacter(Character *c)
	{
		this->c = c;
	}

	//pure virtual functions for interacting with spaces and a menu for moving. The menu returns a pointer to the next space
	virtual void interact() = 0;
	virtual Space* menu() = 0;

};
#endif
