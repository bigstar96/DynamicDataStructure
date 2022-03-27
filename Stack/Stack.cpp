#include "Stack.h"
#include <iostream>



void StackInitialize(Stack& stack)
{
	stack.count = 0;
	stack.top = nullptr;
}

void StackReleaseAll(Stack& stack)
{
	Element* element = stack.top;
	Element* next = nullptr;

	while (element != nullptr)
	{
		next = element->next;
		delete element;
		element = next;
	}

	StackInitialize(stack);
}

void StackPush(Stack& stack, int value)
{
	Element* element = new Element;
	element->value = value;

	element->next = stack.top;
	stack.top = element;
	stack.count++;
}

bool StackPop(Stack& stack)
{
	if (stack.count == 0)
	{
		std::cout << "STACK is EMPTY!" << std::endl;
		return false;
	}

	Element* prevTop = stack.top;
	int value = prevTop->value;

	stack.top = prevTop->next;
	stack.count--;

	delete prevTop;

	std::cout << "POP : " << value << std::endl;

	return true;
}

void StackPrint(Stack& stack)
{
	Element* element = stack.top;

	while (element != nullptr)
	{
		std::cout << element->value << std::endl;
		element = element->next;
	}
}
