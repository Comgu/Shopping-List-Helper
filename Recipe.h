#pragma once
#include <vector>
#include "DataItem.h"
#include "ItemList.h"


/*! Recipe class, subclass of ItemList

	Class stores and includes DataItem objects in a vector for one recipe. 

	Attributes: vector<DataItem*> objects, string name.

	Methods: Constructors, Destructor, get/setName, getObject, getContents, addObject, deleteObject, printAllObjects.
*/
class Recipe : public ItemList
{
private:
	std::string name;							/*!< Name in string type*/
public:
	Recipe();									/*!< Default constructor*/
	Recipe(const std::string& newName);			/*!< Constructor with name*/
	~Recipe();									/*!< Default destructor*/

	std::string getName();												/*!< Gets string name from Recipe attributes*/		
	void setName(const std::string& newName);							/*!< Sets a new name for string name*/
	std::vector<DataItem*> getContents() override;						/*!< Gets the whole vector<DataItem*> objects and returns it*/
	DataItem* getObject(int i) override;								/*!< Gets a DataItem object from position i at vector<DataItem*> objects*/
	void addObject(DataItem* newObject) override;						/*!< Adds a DataItem object to vector*/
	void deleteObject(int pos) override;								/*!< Deletes a DataItem object from vector at position pos*/
	void printAllObjects() override;									/*!< Prints all objects in vector using function toString from DataItem class*/
};
