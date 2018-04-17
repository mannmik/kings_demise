/*****************************************
**Author: Mike Mann
**Description: Character declaration.
*****************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
#include <iostream>
#include "Space.hpp"


class Character
{
private:
	std::string container[4];
	Space *current;
	bool hasDagger;
	bool hasKey;
	bool hasWine;
	bool hasLetter;
	bool success;
	bool failure;


public:
	Character()
	{
		for (int i = 0; i < 4; ++i)
		{
			container[i] = "";
		}

		current = NULL;
		hasDagger = false;
		hasKey = false;
		hasWine = false;
		hasLetter = false;
		success = false;
		failure = false;
	}


	void setSuccess(int x)
	{
		if (x = 1)
			success = true;
	}

	void setFailure(int x)
	{
		if (x = 1)
			failure = true;
	}
	void setDagger(int x)
	{
		if (x = 1)
			hasDagger = true;
	}

	void setKey(int x)
	{
		if(x = 1)
			hasKey = true;
	}

	void setWine(int x)
	{
		if (x = 1)
			hasWine = true;
	}

	void setLetter(int x)
	{
		if (x = 1)
			hasLetter = true;
	}

	bool getDagger()
	{
		return hasDagger;
	}

	bool getKey()
	{
		return hasKey;
	}

	bool getWine()
	{
		return hasWine;
	}

	bool getLetter()
	{
		return hasLetter;
	}

	bool getSuccess()
	{
		return success;
	}

	bool getFailure()
	{
		return failure;
	}
	void setCurrentLocation(Space *current)
	{
		this->current = current;
	}

	Space* getCurrent()
	{
		return current;
	}

	void addItem(std::string s)
	{
		if (container[0] == "")
			container[0] = s;
		else if(container[1] == "")
			container[1] = s;
		else if (container[2] == "")
			container[2] = s;
		else if (container[3] == "")
			container[3] = s;
	}
	
	void printC()
	{
		
		for(int i = 0; i< 4; ++i)
		{
			if(container[i] != "")
				std::cout << container[i] << std::endl;
		}
	}
};
#endif

