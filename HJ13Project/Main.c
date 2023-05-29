#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count = 0;
int n;
int front = 0, rear = 0;
int* queue;

void enQueue(int data) {

	if ((rear + 1) % (n + 1) == front) {
		printf("FULL\n");
		return;
	}

	rear = (rear + 1) % (n + 1);
	queue[rear % (n + 1)] = data;

}

int de() {
	int data;

	if (front == rear) {
		printf("NULL\n");
		return 0;
	}

	data = queue[(front + 1) % (n + 1)];
	front = (front + 1) % (n + 1);
}

void print() {
	int idx = 0;
	idx = (front + 1) % (n + 1);

	do {
		if (front == rear) {
			printf("NULL\n");
			break;
		}
		else if (idx > rear)
			break;
		printf("%c ", queue[idx++ % (n + 1)]);
	} while (1);

}

int main() {
	printf("Max FURIT SIZE : ");
	scanf("%d", &n);
	queue = (int*)malloc(sizeof(int) * (n + 1));

	while (1) {
		int menu, data;
		printf("\n1. Input new fruit\n2. Delete the fruit\n3. print rist \n4. Exit  \n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			printf("Input the Data : ");
			scanf("%s", &data);
			enQueue(data);
			break;
		case 2:
			de();
			break;
		case 3:
			print();
			break;
		case 4:
			exit(1);
			break;
		}
	}

}