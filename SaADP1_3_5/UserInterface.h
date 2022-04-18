#pragma once
#include "ListItem.h"
enum userInterface
{
	AddItem = 1,
	DeleteItem,
	Show,
	Exit,
	Before = 1,
	After = 2,
	List = 1,
	Stack = 2,
	Continue = 1,
};

void printMainMenu();
int userInput();
void workWithUser(ListItem*& pHead, ListItem*& pStack);
void caseAddItem(ListItem*& pHead);
void caseDeleteItem(ListItem*& pHead, ListItem*& pStack);
void caseShow(ListItem* pHead, ListItem* pStack);


