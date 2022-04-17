#include <iostream>
#include "ListItem.h"
ListItem* pHead;

void init(ListItem*& pHead)
{
	pHead->next = NULL;
}

bool isEmpty(ListItem* pHead)
{
	if (pHead == NULL) { return true; }
	else return false;
}

ListItem& search(ListItem* pHead, char currentData)
{
	ListItem* pCurrent = new ListItem;
	pCurrent = pHead->next;

	while ( pCurrent != NULL && pCurrent->data != currentData)
	{
		pCurrent = pCurrent->next;
	}

	if (pCurrent == NULL){std::cout << "There is no such element" << std::endl;}
	else { std::cout << "Item found" << std::endl; }
	return *pCurrent;
}

void deleteItem(ListItem*& pHead, char currentData)
{

}