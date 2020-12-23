#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Circular Buffer Algorithm
typedef struct {
	unsigned int capacity; //size of buffer
	unsigned int tail;  //tail pointer
	unsigned int head;  //head pointer
	unsigned int size;
	float* samples; //Circular Buffer Array
}Circular;

//Initialize the circular buffer
//Eqq=uivalent to creating the empty array
Circular* Buffer_Initialization(unsigned int _capacity)
{
	Circular* myBuffer = (Circular*)malloc(sizeof(Circular)); // Initialize the pointer
	myBuffer->tail = -1;
	myBuffer->head = 0;
	myBuffer->size = 0;
	myBuffer->capacity = _capacity;
	myBuffer->samples = (float*)malloc(_capacity * sizeof(float));
	printf("Tail Position = %d\n", myBuffer->tail);
	printf("Head Position = %d\n", myBuffer->head);
	printf("Position = %d\n", myBuffer->size);
	printf("Max. Size = %d\n", myBuffer->capacity);
	printf("Successfully created circular buffer!");
	return myBuffer;
}

//Enqueue
Circular* Enqueue(Circular*myBuffer,float number)
{
	myBuffer->tail = ((myBuffer->tail) + 1) % myBuffer->capacity;
	myBuffer->samples[myBuffer->tail] = number;
	printf("%2f ", myBuffer->samples[myBuffer->tail]);
	printf("Tail = %d ", myBuffer->tail);
	printf("Head = %d\n", myBuffer->head);
	myBuffer->size = (myBuffer->size) + 1;
	return myBuffer;
}

//Dequeue
Circular* Dequeue_and_Replace(Circular* myBuffer)
{
	float capture = 0;
	capture = myBuffer->samples[myBuffer->head];
	myBuffer->head = ((myBuffer->head) + 1) % myBuffer->capacity;
	printf("The number %2f has been captured!  ", capture);
	printf("The current head position is %d:", myBuffer->head);
	printf("  The current tail position is %d:\n", myBuffer->tail);
	return myBuffer;
}

//Print Circular Array
void Print_Array(Circular* mybuffer)
{
	int count = 0;
	while (count < (mybuffer->capacity))
	{
		printf("%2f ", mybuffer->samples[count]);
		count++;
	}
	printf("\n");
}

int main()
{
	int n = 0;
	float element = 0;
	int times = 0;
	Circular* buffer = NULL;
	printf("Enter the maximum buffer's capacity: \n");
	scanf("%d",&n);
	buffer = Buffer_Initialization(n);
	printf("\n");
	printf("\nInput the items:\n");

	//Enqueue the items into the circular buffer
	while (times < (buffer->capacity))
	{
		scanf("%f", &element);
		buffer = Enqueue(buffer, element);
		times++;
	}
	times = 0;
	printf("The current tail position is %d and the current head position is %d\n", buffer->tail, buffer->head);
	Print_Array(buffer);

	//Dequeue the old item to achieve FIFO (First in- First Out)
	printf("\nInput the number of items to be replaced:\n");
	scanf("%d", &times);
	for (int i = 0; i < times; i++)
	{
		buffer = Dequeue_and_Replace(buffer);
	}
	printf("The current tail position is %d and the current head position is %d\n", buffer->tail, buffer->head);
	times = 0;

	//Replace
	printf("\nInput the new number :\n");
	while (times < (buffer->head))
	{
		scanf("%f", &element);
		buffer = Enqueue(buffer, element);
		times++;
	}
	times = 0;
	Print_Array(buffer);
	system("pause");
}