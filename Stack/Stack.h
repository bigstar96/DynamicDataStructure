#pragma once

enum Command
{
	PUSH = 1,
	POP = 2,
	EXIT = 3
};

struct Element
{
	int value;
	Element* next;
};

struct Stack
{
	int count;
	Element* top;
};



void StackInitialize(Stack& stack);
void StackReleaseAll(Stack& stack);
void StackPush(Stack& stack, int value);
bool StackPop(Stack& stack);
void StackPrint(Stack& stack);
