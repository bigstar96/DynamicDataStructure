#include <iostream>
#include "Stack.h"


void StackPrintInfo()
{
	std::cout << "<STACK>" << std::endl;
	std::cout << "[1] push" << std::endl;
	std::cout << "[2] pop" << std::endl;
	std::cout << "[3] exit" << std::endl;
	std::cout << "---------" << std::endl;
}

void ProcessUserInput(Stack& stack)
{
	int command = -1;
	bool isExit = false;

	while (true)
	{
		StackPrint(stack);

		std::cout << std::endl;
		std::cout << "> ";
		std::cin >> command;
		
		switch (command)
		{
		case PUSH:
		{
			int value;
			std::cout << " push value > ";
			std::cin >> value;
			StackPush(stack, value);
			break;
		}

		case POP:
			StackPop(stack);
			break;

		case EXIT:
			isExit = true;
			break;

		default:
			std::cout << "잘못된 명령어 입니다." << std::endl;
			break;
		}

		if (isExit)
		{
			break;
		}
	}
}

int main()
{
	Stack myStack;

	StackInitialize(myStack);

	StackPrintInfo();
	ProcessUserInput(myStack);

	StackReleaseAll(myStack);

}