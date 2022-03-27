#pragma once

enum Command
{
	ENQUEUE = 1,
	DEQUEUE = 2,
	EXIT = 3
};

struct Element
{
	int value;
	Element* next;
};

struct Queue
{
	int count;		// 원소 개수
	Element* front;	// 앞
	Element* rear;	// 뒤
};

void QueueInitialize(Queue& queue);
void QueueReleaseAll(Queue& queue);
void QueueEnqueue(Queue& queue, int value);
bool QueueDequeue(Queue& queue);
void QueuePrint(Queue& queue);