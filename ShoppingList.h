#pragma once
#include "itemlist.h"
#include "recipe.h"


/*! ShoppingList class, subclass of ItemList

	Class stores DataItem objects in a vector for one ShoppingList. Objects are combined by name and quantityType if possible. 

	Attributes: vector<DataItem*> objects, string name.

	Methods: Constructors, Destructor, get/setName, getObject, getContents, addObject(DataItem*), addObject(Recipe*), deleteObject, printAllObjects, findObjectPos, findIfObjectExists.
*/
class ShoppingList : public ItemList
{
private:
	std::string name;													/*!< Name in string type*/
public:
	ShoppingList(const std::string& newName);							/*!< Constructor with name*/
	ShoppingList();														/*!< Default constructor*/
	std::string getName();												/*!< Gets string name from ShoppingList attributes*/						
	void setName(const std::string& newName);							/*!< Sets a new name for string name*/
	std::shared_ptr<DataItem> getObject(int i) override;								/*!< Gets a DataItem object from position i at vector<DataItem*> objects*/
	std::vector<std::shared_ptr<DataItem>> getContents() override;						/*!< Gets the whole vector<DataItem*> objects and returns it*/
	void addObject(std::shared_ptr<DataItem> newObject) override;						/*!< Adds a DataItem object to vector. Checks if object exists already and combines its quantity with existing if possible. Overloaded function with DataItem* parameter*/
	void addObject(std::shared_ptr<Recipe> recipe);								/*!< Adds all DataItem objects from a Recipe objects to vector. Checks if object exists already and combines its quantity with existing if possible. Overloaded function with Recipe* parameter*/
	void deleteObject(int pos) override;								/*!< Deletes a DataItem object from vector at position pos*/
	std::string toString() override;									/*!< Prints all objects in vector using function toString from DataItem class*/
	int findObjectPos(std::shared_ptr<DataItem> object);								/*!< Finds position of DataItem* object and returns it in int type. Should only be used if object exists*/
	bool findIfObjectExistsName(std::shared_ptr<DataItem> object);						/*!< Finds if duplicate object exists in vector and returns true if it does. Compares objects by name*/

};