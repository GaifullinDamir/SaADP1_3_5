#pragma once
struct ListItem
{
	char data;
	ListItem* next;
};

void init(ListItem*& pHead);
bool isEmpty(ListItem* pHead);
void searchPrevious(ListItem* pHead, ListItem*& pPrevious, ListItem*& pCurrent, char data);
void search(ListItem* pHead, ListItem*& pCurrent, char data);
void deleteItem(ListItem*& pHead, ListItem*& pPrevious, char data);
void addAfter(ListItem*& pHead, char data);
void addBefore(ListItem*& pHead, char data);
