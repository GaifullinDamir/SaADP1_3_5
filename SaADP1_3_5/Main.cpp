#include <iostream>
#include "UserInterface.h"
#include "ListItem.h"


int main()
{
	ListItem* pHead = new ListItem;
	ListItem* pStack = new ListItem;
	init(pHead, pStack);
	workWithUser(pHead, pStack);
};