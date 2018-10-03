#include <iostream>
#include "functions.h"
#include "DataItem.h"
#include "DataItemList.h"
#include "Recipe.h"
#include "ShoppingList.h"

int main()
{
	// Testing for DataItem class & DataItemList class
	std::string newName = "Jauheliha";
	std::string newQuantityType = "g";
	double newQuantity = 400;
	std::string newName2 = "Kana";
	std::string newQuantityType2 = "g";
	double newQuantity2 = 300;
	std::string newName3 = "Kana";
	std::string newQuantityType3 = "g";
	double newQuantity3 = 300;
	DataItem* test1 = new DataItem(newName, newQuantity, newQuantityType);
	DataItem* test2 = new DataItem(newName2, newQuantity2, newQuantityType2);
	DataItem* test3 = new DataItem(newName3, newQuantity3, newQuantityType3);
	DataItemList *testList = DataItemList::getInstance();
	testList->addObject(test1);
	testList->addObject(test2);
	testList->printAllObjects();
	testList->getObject(0);
	if (testList->findIfObjectExists(test1) == true)
	{
		std::cout << "\nExists";
		int pos = testList->findObjectPos(test1);
		std::cout << " at position " << pos << "\n";
	}
	else
	{
		std::cout << "\nDoesn't exist\n";
		testList->addObject(test3);
	}

	// Testing for Recipe class
	std::string newRecipeName = "Keitto";
	Recipe *recipe1 = new Recipe(newRecipeName);
	recipe1->addObject(test3);
	recipe1->addObject(test2);
	std::string newRecipeName2 = "Keitto 2";
	Recipe *recipe2 = new Recipe(newRecipeName2);
	recipe2->addObject(test1);
	recipe2->addObject(test2);
	recipe1->printAllObjects();
	recipe2->printAllObjects();

	// Testing for ShoppingList class
	ShoppingList *shopping1 = new ShoppingList();
	shopping1->addObject(test1);
	shopping1->addObject(test2);
	shopping1->addObject(test3);
	shopping1->printAllObjects();




}