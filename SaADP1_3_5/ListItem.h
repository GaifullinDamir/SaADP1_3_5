#pragma once
struct ListItem
{
	int data;
	ListItem* next;
};

void init(ListItem*& pHead, ListItem*& pStack);
bool isEmpty(ListItem* pHead);
bool searchPrevious(ListItem* pHead, ListItem*& pPrevious, ListItem*& pCurrent, int data);
bool search(ListItem* pHead, ListItem*& pCurrent, int data);
void deleteItem(ListItem* pHead, ListItem*& pStack, ListItem*& pPrevious, ListItem*& pCurrent, int data);
void addAfter(ListItem*& pHead, ListItem*& pCurrent, int data);
void addBefore(ListItem* pHead, ListItem*& pCurrent, ListItem*& pPrevious, int data);
void show(ListItem* pHead);