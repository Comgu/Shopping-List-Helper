#include <iostream>
#include <sstream>
#include <fstream>
#include "stdlib.h"
#include "functions.h"
#include "DataItem.h"
#include "DataItemList.h"
#include "Recipe.h"
#include "RecipeList.h"
#include "ShoppingList.h"
#include "windows.h"

int main()		// TO DO: Fix Infinite loops (related to str1, num, str2). Add Switch implementation(?). Add functions to writing to csv (?)
{
	DataItemList& itemList = DataItemList::getInstance();
	RecipeList& recipeList = RecipeList::getInstance();
	ShoppingList shoppingList{ "Shopping List" };
	
	std::ifstream infile( "items.csv" );
	bool isName=true;
	std::string line;
	char delim;
	std::string cName;
	double cQuant=0;
	std::string cQt;
	while (infile.good()) {
		while (getline(infile, line)) {
			std::stringstream ss;
			ss << line;
			while (std::getline(ss, line, ',')) {
				delim = line.at(0);
				if (isdigit(delim) != 0) {
					cQuant = std::stoi(line);
					continue;
				}
				if (isName == true) {
					cName = line;
					isName = false;
				}
				else { 
					cQt = line;
					isName = true;
				}
			}
			std::shared_ptr<DataItem> item{ new DataItem{cName,cQuant,cQt} };
			itemList.addObject(item);
		}
	}
	infile.close();

	std::ifstream infile2("recipes.csv");
	while (infile2.good()) {
		while (getline(infile2, line)) {
			std::stringstream ss;
			ss << line;
			std::getline(ss, line, ',');
			cName = line;
			std::shared_ptr<Recipe> recipe{ new Recipe{cName} };
			while (std::getline(ss, line, ',')) {
				std::stringstream ss2;
				ss2 << line;
				ss2 >> cName;
				ss2 >> cQuant;
				ss2 >> cQt;
				recipe->addObject(itemList.getObject(itemList.findObjectPos(cName, cQuant, cQt)));
			}
			recipeList.addObject(recipe);
		}
	}
	infile2.close();
	
	bool mainMenu = true;
	std::string action = "9";
	std::string str1, str2;
	double num;

	while (mainMenu == true) {
		std::cout << "1 - Add Food Item\n";
		std::cout << "2 - Create new Recipe\n";
		std::cout << "3 - Create Shopping List\n";
		std::cout << "4 - Print Shopping List\n";
		std::cout << "9 - EXIT\n";
		std::cin >> action;
		system("CLS");
		if(action == "1"){
			std::cout << "Enter name and quantity of item (Example: Meat 400g) Don't use multiple words in name\n";
			std::cin >> str1;
			std::cin >> num;
			std::cin >> str2;
			std::shared_ptr<DataItem> item{ new DataItem{str1,num,str2} };
			if (itemList.findIfObjectExists(item) == false) {
				std::ofstream onfile;
				onfile.open("items.csv", std::ios_base::app);
				onfile.seekp(0, std::ios::end);
				onfile << std::endl << str1 << "," << num << "," << str2;
				onfile.close();
				itemList.addObject(item);
			}
			system("CLS");
			std::cout << "Added " << str1 << "\n";
			continue;
			}
		if(action == "2"){
			std::cout << "Enter name of recipe\n";
			std::cin >> str1;
			system("CLS");
			if (recipeList.findIfObjectExists(str1)) {
				std::cout << "Recipe " << str1 << " already exists\n";
				continue;
			}
			std::shared_ptr<Recipe> recipe{ new Recipe{str1} };
			std::cout << "Add items to recipe\n";
			bool newItems = true;
			while (newItems == true) {				// Infinite Loop with multi word str1
				std::cout << "Enter name and quantity of item (END ends) Don't use multiple words in name\n";
				std::cin >> str1;
				if (str1 == "END") {
					newItems = false;
					system("CLS");
					break;
				}
				std::cin >> num;
				std::cin >> str2;
				if (itemList.findIfObjectExists(str1, num, str2) == true)
					recipe->addObject(itemList.getObject(itemList.findObjectPos(str1, num, str2)));
				else {
					std::shared_ptr<DataItem> item{ new DataItem{str1,num,str2} };
					std::ofstream onfile;
					onfile.open("items.csv", std::ios_base::app);
					onfile.seekp(0, std::ios::end);
					onfile << std::endl << str1 << "," << num << "," << str2;
					onfile.close();
					itemList.addObject(item);
					recipe->addObject(item);
				}
			}
			if (recipeList.findIfObjectExists(recipe) == false) {
				std::ofstream onfile;
				onfile.open("recipes.csv", std::ios_base::app);
				onfile.seekp(0, std::ios::end);
				onfile << std::endl << recipe->getName() << ",";
				std::vector<std::shared_ptr<DataItem>> recipeItems = recipe->getContents();
				for (unsigned int i = 0; i < recipe->getContents().size(); i++) {
					if (i + 1 == recipe->getContents().size())
						onfile << recipeItems[i]->getName() << " " << recipeItems[i]->getQuantity() << recipeItems[i]->getQuantityType();
					else
					onfile << recipeItems[i]->getName() << " " << recipeItems[i]->getQuantity() << recipeItems[i]->getQuantityType() << ",";
				}
				onfile.close();

				recipeList.addObject(recipe);
			}
			system("CLS");
			continue;
		}
		if(action == "3") {
			std::cout << "Creating new shopping list\n";
			bool newItems = true;
			std::string action2;
			while (newItems == true) {
				std::cout << "1 - Add a recipe\n";
				std::cout << "2 - Add an item\n";
				std::cout << "9 - List done\n";
				std::cin >> action2;
				if (action2 == "1") {
					recipeList.printRecipeNames();
					std::cout << "Enter recipe name\n";				
					std::cin >> str1;
					if (recipeList.findIfObjectExists(str1) == true) {
						std::shared_ptr<Recipe> temp{ recipeList.getObject(recipeList.findObjectPos(str1)) };
						shoppingList.addObject(temp);			
						system("CLS");
						std::cout << "Added " << str1 << "\n";
					}
					else 
						std::cout << "Cannot find recipe: " << str1 << "\n";
					continue;
				}
				if (action2 == "2") {			// Infinite Loop with multi word str1
					std::cout << "Enter item name and quantity\n";				
					std::cin >> str1;
					std::cin >> num;
					std::cin >> str2;
					if (itemList.findIfObjectExists(str1, num, str2) == true)
						shoppingList.addObject(itemList.getObject(itemList.findObjectPos(str1, num, str2)));
					else {
						std::shared_ptr<DataItem> item{ new DataItem{str1,num,str2} };
						std::ofstream onfile;
						onfile.open("items.csv", std::ios_base::app);
						onfile.seekp(0, std::ios::end);
						onfile << std::endl << str1 << "," << num << "," << str2;
						onfile.close();
						itemList.addObject(item);
						shoppingList.addObject(item);
						system("CLS");
						std::cout << "Added " << str1 << "\n";
					}
					continue;
				}
				if (action2 == "9") {
					newItems = false;
					continue;
				}
				std::cout << "Invalid input\n";
			}
			system("CLS");
			continue;
		}
		if (action == "4") {
			shoppingList.printAllObjects();
			continue;
		}
		if(action == "9") {
			mainMenu = false;
			std::cout << "Exiting...\n";
			Sleep(500);
			continue;
		}
		std::cout << "Invalid input\n";
	}
}
