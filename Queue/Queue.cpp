#include "Queue.h"
#include <iostream>

void QueueInitialize(Queue& queue)
{
	queue.count = 0;
	queue.front = queue.rear = nullptr;
}

void QueueReleaseAll(Queue& queue)
{
	Element* element = queue.front;
	Element* next = nullptr;

	while (element != nullptr)
	{
		next = element->next;
		delete element;
		element = next;
	}

	QueueInitialize(queue);
}

void QueueEnqueue(Queue& queue, int value)
{
	Element* element = new Element;
	element->value = value;
	element->next = nullptr;

	if (queue.count == 0)
	{
		queue.front = element;
		queue.rear = element;
	}
	else
	{
		queue.rear->next = element;
		queue.rear = element;
	}

	queue.count++;
}

bool QueueDequeue(Queue& queue)
{
	if (queue.count == 0)
	{
		std::cout << "QUEUE is EMPTY" << std::endl;
		return false;
	}

	Element* element = queue.front;

	std::cout << "dequeue : " << element->value << std::endl;

	queue.front = element->next;

	delete element;
	queue.count--;

	if (queue.count == 0)
	{
		QueueInitialize(queue);
	}

	return true;
}

void QueuePrint(Queue& queue)
{
	Element* element = queue.front;

	while (element != nullptr)
	{
		std::cout << element->value << std::endl;
		element = element->next;
	}
}
