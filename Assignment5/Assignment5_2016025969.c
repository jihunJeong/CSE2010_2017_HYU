#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100000

int HEAP_FULL(n) {
	if (n == MAX_ELEMENTS - 1) {
		return 1;
	} else {
		return 0;
	}
}

int HEAP_EMPTY(n) {
	if (!n) {
		return 1;
	} else {
		return 0;
	}
}

typedef struct element {
	int key;
	int abs;
}element;

element heap[MAX_ELEMENTS];
int n = 0;

element MakeElement(int input);
void InsertAbsHeap(element item, int* n);
element DeleteAbsHeap(int* n);

int main()
{
	int command_num;
	scanf("%d", &command_num);
	element item;

	while (command_num > 0) {
		int input;
		scanf("%d", &input);

		switch (input) {
			case 0:
				item = DeleteAbsHeap(&n);
				printf("%d\n", item.key);
				break;
			default:
				item = MakeElement(input);
				InsertAbsHeap(item, &n);
				break;
		}

		command_num -= 1;
	}
}

element MakeElement(int input) {
	element item;
	item.abs = 0;

	if (input < 0) {
		item.abs -= input;
	} else {
		item.abs = input;
	}

	item.key = input;
	return item;
}

void InsertAbsHeap(element item, int* n) {
	int i;
	
	if (HEAP_FULL(*n)) {
		fprintf(stderr, "The heap is full.\n");
		exit(1);
	}
	
	i = ++(*n);
	
	while (i != 1 && item.abs <= heap[i / 2].abs) {
		if (item.key > heap[i / 2].key) {
			break;
		}
		heap[i] = heap[i / 2];
		i /= 2;
	}
	
	heap[i] = item;
}

element DeleteAbsHeap(int* n) {
	element item, temp;
	int parent, child;

	if (HEAP_EMPTY(*n)) {
		item.key = 0;
		return item;
	}
	
	item = heap[1];
	temp = heap[(*n)--];
	parent = 1; child = 2;

	while (child <= *n) {
		if (child < *n && heap[child].abs == heap[child + 1].abs && heap[child].key > heap[child + 1].key) {
			child++;
		}

		if (child < *n && heap[child].abs > heap[child + 1].abs) {
			child++;
		}

		if (temp.abs <= heap[child].abs && temp.key <= heap[child].key) {
			break;
		}

		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}

	heap[parent] = temp;
	return item;
}
