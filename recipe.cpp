#include "recipe.h"
#include <sstream>

Recipe::Recipe(const std::string& newName) : name(newName) {}

std::string Recipe::getName() const
{
	return name;
}

void Recipe::setName(const std::string& newName)
{
	name = newName;
}

void Recipe::addObject(const std::shared_ptr<DataItem>& newObject)
{
	objects.push_back(newObject);
}

std::string Recipe::toString() const
{
	std::stringstream outputString;
	outputString << name << " contents:\n";
	for (unsigned int i = 0; i < objects.size(); i++)
		outputString << objects[i]->toString();							// Prints output from toString function

	return outputString.str();
}