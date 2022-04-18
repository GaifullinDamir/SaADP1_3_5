#include <iostream>
#include "ListItem.h"

void init(ListItem*& pHead, ListItem*& pStack)
{
	pHead->next = NULL;
	pStack->next = NULL;
}

bool isEmpty(ListItem* pHead)
{
	if (pHead->next == NULL) { return true; }
	else return false;
}

bool searchPrevious(ListItem* pHead, ListItem*& pPrevious, ListItem*& pCurrent, int data)
{
	if (isEmpty(pHead)) { std::cout << "List is empty" << std::endl; }
	else
	{
		pCurrent = new ListItem;
		pPrevious = pHead;
		pCurrent = pHead->next;

		while (pCurrent != NULL)
		{
			if (pCurrent->data == data)
			{
				return true;
			}
			pPrevious = pCurrent;
			pCurrent = pCurrent->next;
		}
		if (pCurrent == NULL) { return false;}
	}
	

}

bool search(ListItem* pHead, ListItem*& pCurrent, int data)
{
	if (isEmpty(pHead)) { std::cout << "List is empty" << std::endl; }
	else
	{
		pCurrent = new ListItem;
		pCurrent = pHead->next;

		while (pCurrent != NULL)
		{
			if (pCurrent->data == data)
			{
				return true;
			}
			pCurrent = pCurrent->next;
		}

		if (pCurrent == NULL) { return false; }
	}
}

void deleteItem(ListItem* pHead, ListItem*& pStack, ListItem*& pPrevious, ListItem*& pCurrent, int data)
{
	searchPrevious(pHead, pPrevious, pCurrent, data);
	if (!isEmpty(pHead))
	{
		pPrevious->next = pCurrent->next;
		pCurrent->next = pStack->next;
		pStack->next = pCurrent;
	}
	else { std::cout << "List is empty!" << std::endl; }
}

void addAfter(ListItem*& pHead, ListItem*& pCurrent, int data)
{
	if (!isEmpty(pHead))
	{
		ListItem* pAdded = new ListItem;
		pAdded->data = data;
		pAdded->next = pCurrent->next;
		pCurrent->next = pAdded;
	}
	else
	{
		ListItem* pTemporary = new ListItem; 
		pTemporary->data = data;
		pTemporary->next = NULL;
		pHead->next = pTemporary;
	}
	
}

void addBefore(ListItem* pHead, ListItem*& pCurrent, ListItem*& pPrevious, int data)
{
	if (!isEmpty(pHead))
	{
		ListItem* pAdded = new ListItem;
		pAdded->data = data;
		pAdded->next = pCurrent;
		pPrevious->next = pAdded;
	}
	else { std::cout << "List is empty." << std::endl; }
}

void show(ListItem* pHead)
{
	if (!isEmpty(pHead))
	{
		ListItem* pCurrent = pHead->next;
		while (pCurrent != NULL)
		{
			std::cout << "   " << pCurrent->data << std::endl;
			pCurrent = pCurrent->next;
		}
		std::cout << std::endl;
	}
	else std::cout << "List is empty."<< std::endl;
}
