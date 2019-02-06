#include "recipelist.h"
#include <iostream>
#include <sstream>

void RecipeList::addObject(std::shared_ptr<Recipe> newObject)
{
	if (findIfObjectExists(newObject->getName()) == false)				// If object doesn't exist, adds it to vector, else outputs warning message
		recipes.push_back(newObject);
	else
		std::cout << "Recipe " << newObject->getName() << " already exists\n";
}

std::shared_ptr<Recipe> RecipeList::getObject(int i)
{
	return recipes[i];
}

RecipeList& RecipeList::getInstance()
{
	static RecipeList instance;

	return instance;
}

std::string RecipeList::toString()
{
	std::stringstream outputString;
	for (unsigned int i = 0; i < recipes.size(); i++)
		outputString << recipes[i]->toString();							// Prints output from toString function

	return outputString.str();
}

std::string RecipeList::toStringNames() {
	std::stringstream outputString;
	outputString << "Recipes:\n";
	for (unsigned int i = 0; i < recipes.size(); i++)
		outputString << recipes[i]->getName() << "\n";							// Prints output from getName function

	return outputString.str();
}

int RecipeList::findObjectPos(std::shared_ptr<Recipe> recipe) {
	for (unsigned int i = 0; i < recipes.size(); i++) {													// Loop for the size of vector objects{
		if (compareStrings(recipe->getName(), recipes[i]->getName()) == true)										// Compares by name using helper function compareStrings
			return i;																			// Returns position
	}
	return 0;				// Should not happen 
}

int RecipeList::findObjectPos(std::string name) {
	for (unsigned int i = 0; i < recipes.size(); i++) {													// Loop for the size of vector objects{
		if (compareStrings(name, recipes[i]->getName()) == true)										// Compares by name using helper function compareStrings
					return i;																			// Returns position
	}
	return 0;				// Should not happen 
}

bool RecipeList::findIfObjectExists(std::shared_ptr<Recipe> recipe) {
	for (unsigned int i = 0; i < recipes.size(); i++){														// Loop for the size of vector objects
		if (compareStrings(recipe->getName(), recipes[i]->getName()) == true)								// Compares by name using helper function compareStrings
					return true;
	}
	return false;
}

bool RecipeList::findIfObjectExists(std::string name) {
	for (unsigned int i = 0; i < recipes.size(); i++) {														// Loop for the size of vector objects
		if (compareStrings(name, recipes[i]->getName()) == true)								// Compares by name using helper function compareStrings
			return true;
	}
	return false;
}