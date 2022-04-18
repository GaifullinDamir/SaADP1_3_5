#include "UserInterface.h"
#include <iostream>
#include <string>
#include "UserInterface.h"
#include "ListItem.h"

void printMainMenu()
{
	std::cout << std::endl;
	std::cout << "1. Add an element to the list." << std::endl;
	std::cout << "2. Remove an element from the list." << std::endl;
	std::cout << "3. Display list on screen." << std::endl;
	std::cout << "4. Exit." << std::endl;
	std::cout << std::endl;
}

void printAddMenu()
{
	std::cout << std::endl;
	std::cout << "1. Insert element before specified." << std::endl;
	std::cout << "2. Insert element after specified." << std::endl;
	std::cout << std::endl;
}

void printDisplayMenu()
{
	std::cout << std::endl;
	std::cout << "1. Display list." << std::endl;
	std::cout << "2. Display additional stack." << std::endl;
	std::cout << std::endl;
}

int userInput()
{
	int option = 0;
	bool check = true;
	std::string optionInput;
	while (check)
	{
		try
		{
			std::cout << "   Enter a number, please: ";
			std::cin >> optionInput;
			option = std::stoi(optionInput);
			check = false;
		}
		catch (const std::exception&)
		{
			std::cout << "   Please enter a number!" << std::endl;
			std::cout << std::endl;
			check = true;
		}
	}
	return option;
}

void workWithUser(ListItem*& pHead, ListItem*& pStack)
{
	bool work = true;
	while (work)
	{
		printMainMenu();
		std::cout << "   What do you want to do? " << std::endl;
		std::cout << std::endl;
		int option = userInput();
		switch (option)
		{
		case(AddItem):
		{
			caseAddItem(pHead);
			break;
		}
		case(DeleteItem):
		{
			caseDeleteItem(pHead, pStack);
			break;
		}
		case(Show):
			caseShow(pHead, pStack);
			break;
		case(Exit):
			work = false;
			break;
		default:
			std::cout << "   There is no such menu item." << std::endl;
			break;
		}
	}
}

void caseAddItem(ListItem*& pHead)
{
	ListItem* pCurrent = new ListItem;
	ListItem* pPrevious = new ListItem;

	if (isEmpty(pHead))
	{
		std::cout << "   Enter the item to add." << std::endl;
		int data = userInput();
		addAfter(pHead, pCurrent, data);
		std::cout << std::endl;
		std::cout << "   Item added." << std::endl;
		std::cout << std::endl;
	}
	else 
	{
		std::cout << "   Enter an element instead of or after which to insert a new one." << std::endl;
		int currentData = userInput();
		bool check = true;
		check = search(pHead, pCurrent, currentData);
		if (check)
		{
			printAddMenu();
			int beforeOrAfter = userInput();
			std::cout << "   Enter the item to add." << std::endl;
			int data = userInput();

			switch (beforeOrAfter)
			{
				case(Before):
				{
					searchPrevious(pHead, pPrevious, pCurrent, currentData);
					addBefore(pHead, pCurrent, pPrevious, data);
					break;
				}
				case(After):
				{
					addAfter(pHead, pCurrent, data);
					break;
				}
				default:
					std::cout << "   There is no such menu item." << std::endl;
					break;
			}
			std::cout << std::endl;
			std::cout << "   Item added." << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "   There is no such element." << std::endl;
		}
	}

}

void caseDeleteItem(ListItem*& pHead, ListItem*& pStack)
{
	if (isEmpty(pHead))
	{
		std::cout << "   Nothing to delete." << std::endl;
	}
	std::cout << "   Enter the item to delete." << std::endl;
	int currentData = userInput();
	ListItem* pCurrent = new ListItem;
	ListItem* pPrevious = new ListItem;
	bool check = searchPrevious(pHead, pPrevious, pCurrent, currentData);
	if (check)
	{
		deleteItem(pHead, pStack, pPrevious, pCurrent, currentData);
		std::cout << std::endl;
		std::cout << "   Item deleted." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "   There is no such element." << std::endl;
	}
}

void caseShow(ListItem* pHead, ListItem* pStack)
{
	if (isEmpty(pHead)) { std::cout << "   Nothing to show." << std::endl; }
	else
	{
		printDisplayMenu();
		std::cout << "   Enter (1) - show list, (2) - show stack." << std::endl;
		switch (userInput())
		{
			case(List):
				show(pHead);
				break;
			case(Stack):
				show(pStack);
				break;
			default:
				break;
		}
	}
}
