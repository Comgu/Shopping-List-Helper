#include <iostream>
#include "functions.h"
#include "DataItem.h"
#include "DataItemList.h"
#include "Recipe.h"
#include "ShoppingList.h"

int main()
{
	// Testing scanning
	std::string str1, str2;
	double val1;
	std::cout << "Enter item name\n";
	std::cin >> str1;
	std::cout << "Enter quantity number (Example: 1000)\n";
	std::cin >> val1;
	std::cout << "Enter quantity type (Example: kg, g)\n";
	std::cin >> str2;

	// Testing for DataItem class & DataItemList class
	//std::string newName = "Jauheliha";
	//std::string newQuantityType = "g";
	//double newQuantity = 400;
	std::string newName2 = "Kana";
	std::string newQuantityType2 = "g";
	double newQuantity2 = 300;
	std::string newName3 = "kana";
	std::string newQuantityType3 = "g";
	double newQuantity3 = 300;
	DataItem* cmdLineItem = new DataItem(str1, val1, str2);
	DataItem* kana300 = new DataItem(newName2, newQuantity2, newQuantityType2);
	DataItem* kana300dupli = new DataItem(newName3, newQuantity3, newQuantityType3);
	DataItem* porkkana = new DataItem("Porkkana", 6, "kpl");
	DataItem* kaali = new DataItem("Kaali", 1, "kpl");
	DataItemList *testList = DataItemList::getInstance();
	testList->addObject(cmdLineItem);
	testList->addObject(kana300);
	testList->addObject(kana300dupli);
	testList->addObject(porkkana);
	testList->addObject(kaali);
	std::cout << "\nPrinting DataItemList:\n";
	testList->printAllObjects();
	testList->getObject(0);

	// Testing for Recipe class
	std::string newRecipeName = "Keitto";
	Recipe *recipe1 = new Recipe(newRecipeName);
	recipe1->addObject(kana300dupli);
	recipe1->addObject(kana300);
	recipe1->addObject(porkkana);
	std::string newRecipeName2 = "Keitto 2";
	Recipe *recipe2 = new Recipe(newRecipeName2);
	recipe2->addObject(cmdLineItem);
	recipe2->addObject(kana300);
	std::cout << "\nPrinting Recipes:\n";
	recipe1->printAllObjects();
	recipe2->printAllObjects();

	// Testing for ShoppingList class
	std::string newShoppingListName = "Lista 1";
	ShoppingList *shopping1 = new ShoppingList(newShoppingListName);
	shopping1->addObject(recipe2);
	shopping1->addObject(cmdLineItem);
	shopping1->addObject(kana300);
	shopping1->addObject(kana300dupli);
	shopping1->addObject(recipe1);
	std::cout << "\nPrinting ShoppingList:\n";
	shopping1->printAllObjects();

	// Testing for Functions template function
	int elementCount = findListItemCount(shopping1);
	std::cout << "\nElement count in " << shopping1->getName() << " is " << elementCount;
	elementCount = findListItemCount(recipe1);
	std::cout << "\nElement count in " << recipe1->getName() << " is " << elementCount;
	elementCount = findListItemCount(recipe2);
	std::cout << "\nElement count in " << recipe2->getName() << " is " << elementCount;
	elementCount = findListItemCount(testList);
	std::cout << "\nElement count of DataItemList"  << " is " << elementCount << "\n";

}