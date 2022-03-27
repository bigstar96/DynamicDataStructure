#include <iostream>
#include "Queue.h"

void QueuePrintInfo()
{
	std::cout << "<QUEUE>" << std::endl;
	std::cout << "[1] enqueue" << std::endl;
	std::cout << "[2] dequeue" << std::endl;
	std::cout << "[3] exit" << std::endl;
	std::cout << "-----------" << std::endl;
}

void QueueProcessUserInput(Queue& queue)
{
	int command = -1;
	bool isExit = false;

	while (true)
	{
		QueuePrint(queue);

		std::cout << std::endl;
		std::cout << "> ";
		std::cin >> command;
		switch (command)
		{
		case ENQUEUE:
		{
			int value;
			std::cout << " enqueue > ";
			std::cin >> value;
			QueueEnqueue(queue, value);
			break;
		}

		case DEQUEUE:
			QueueDequeue(queue);
			break;

		case EXIT:
			isExit = true;
			break;

		default:
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
	Queue myQueue;

	QueueInitialize(myQueue);

	QueuePrintInfo();
	QueueProcessUserInput(myQueue);

	QueueReleaseAll(myQueue);
}