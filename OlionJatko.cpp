#include <iostream>
#include "functions.h"
#include "DataItem.h"
#include "DataItemList.h"
#include "Recipe.h"
#include "ShoppingList.h"
#include "Factory.h"

/* Catch provides main()

int main()
{
	// Testing scanning
	std::cout << "Testing Scanning\n";
	std::string str1, str2;
	double val1;
	std::cout << "Enter item name\n";
	std::cin >> str1;
	std::cout << "Enter quantity and quantity type(Example 400 g)\n";
	std::cin >> val1;
	std::cin >> str2;

	// Testing for DataItem class & DataItemList class
	std::cout << "\nTesting DataItem & DataItemList";
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
	testList->printAllObjects();
	testList->getObject(0);

	// Testing for Recipe class
	std::cout << "\nTesting Recipe";
	Factory* factory = new ListFactory;
	Recipe * recipe1 = factory->createRecipe();
	recipe1->setName("Baklava");
	recipe1->addObject(kana300dupli);
	recipe1->addObject(kana300);
	recipe1->addObject(porkkana);
	Recipe * recipe2 = factory->createRecipe("Keitto");
	recipe2->addObject(cmdLineItem);
	recipe2->addObject(kana300);
	recipe1->printAllObjects();
	recipe2->printAllObjects();

	// Testing for ShoppingList class
	std::cout << "\nTesting ShoppingList";
	ShoppingList * shopping1 = factory->createShoppingList("Ostoslista 1");
	shopping1->addObject(recipe2);
	shopping1->addObject(cmdLineItem);
	shopping1->addObject(kana300);
	shopping1->addObject(kana300dupli);
	shopping1->addObject(recipe1);
	shopping1->printAllObjects();

	// Testing for Functions template function
	std::cout << "\nTesting template function";
	int elementCount = findListItemCount(shopping1);
	std::cout << "\nElement count in " << shopping1->getName() << " is " << elementCount;
	elementCount = findListItemCount(recipe1);
	std::cout << "\nElement count in " << recipe1->getName() << " is " << elementCount;
	elementCount = findListItemCount(recipe2);
	std::cout << "\nElement count in " << recipe2->getName() << " is " << elementCount;
	elementCount = findListItemCount(testList);
	std::cout << "\nElement count of DataItemList"  << " is " << elementCount << "\n";

	// Testing for delete func
	std::cout << "\nTesting delete function";
	shopping1->deleteObject(0);
	shopping1->printAllObjects();
	recipe1->deleteObject(0);
	recipe1->printAllObjects();
	testList->deleteObject(0);
	testList->printAllObjects();

	elementCount = findListItemCount(shopping1);
	std::cout << "\nElement count in " << shopping1->getName() << " is " << elementCount;
	elementCount = findListItemCount(recipe1);
	std::cout << "\nElement count in " << recipe1->getName() << " is " << elementCount;
	elementCount = findListItemCount(recipe2);
	std::cout << "\nElement count in " << recipe2->getName() << " is " << elementCount;
	elementCount = findListItemCount(testList);
	std::cout << "\nElement count of DataItemList" << " is " << elementCount << "\n";
	
}

*/

