#pragma once
struct ListItem
{
	char data;
	ListItem* next;
};

void init(ListItem*& pHead);
bool isEmpty(ListItem* pHead);
ListItem& search(ListItem* pHead, char currentData);
void deleteItem(ListItem*& pHead, char currentData);
void addItemAfter(ListItem*& pHead, char data);
void addItemBefore(ListItem*& pHead, char data);
