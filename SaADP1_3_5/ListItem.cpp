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

void searchPrevious(ListItem* pHead, ListItem*& pPrevious, ListItem*& pCurrent, char data)
{
	pCurrent = new ListItem;
	pPrevious = pHead;
	pCurrent = pHead->next;

	while ( pCurrent != NULL && pCurrent->data != data)
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->next;
	}

	if (pCurrent == NULL){std::cout << "There is no such element" << std::endl;}
	else {std::cout << "Item found" << std::endl;}

}

void search(ListItem* pHead, ListItem*& pCurrent, char data)
{
	pCurrent = new ListItem;
	pCurrent = pHead->next;

	while (pCurrent != NULL && pCurrent->data != data)
	{
		pCurrent = pCurrent->next;
	}

	if (pCurrent == NULL) { std::cout << "There is no such element" << std::endl; }
	else { std::cout << "Item found" << std::endl; }
}

void deleteItem(ListItem*& pHead, ListItem*& pPrevious, char data)
{
	ListItem* pCurrent = new ListItem;
	searchPrevious(pHead, pPrevious, pCurrent, data);
	if (!isEmpty(pHead))
	{
		pPrevious->next = pCurrent->next;
		delete pCurrent;
		pCurrent = NULL;
	}
	else { std::cout << "List is empty!" << std::endl; }
}

void addAfter(ListItem*& pHead, char data)
{
	ListItem* pCurrent = new ListItem;
	search(pHead, pCurrent, data);
	ListItem* pAdded = new ListItem;
	pAdded->data = data;
	pAdded->next = pCurrent->next;
	pCurrent->next = pAdded;
}

void addBefore(ListItem*& pHead, char data)
{
	ListItem* pPrevious = new ListItem;
	ListItem* pCurrent = new ListItem;
	searchPrevious(pHead, pPrevious, pCurrent, data);
	ListItem* pAdded = new ListItem;
	pAdded->data = data;
	pAdded->next = pCurrent;
	pPrevious->next = pAdded;
}

