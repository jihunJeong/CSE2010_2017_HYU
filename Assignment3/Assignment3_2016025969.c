#include <stdio.h>
#include <stdlib.h>

#define arraySize 100

typedef struct stack *Stack;

typedef struct stack {
	char *array;
	int size;
	int top;
}stack;

Stack CreateStack ();
Stack MakeEmptyStack (Stack s);
int IsEmpty (Stack s);
void Push (char x, Stack s);
char Pop (Stack s);
void DeleteStack (Stack s);

int main()
{
	while (1)
	{
		char out[100];
		int cnt = 0, i = 0, chk = 0;
		Stack s = CreateStack();

		while (1)
		{
			char input;
			scanf_s(" %c", &input, sizeof(input));

			if (input == '!') {
				DeleteStack(s);
				return 0;
			} else if (input == '#') {
				if (s->top == -1 && chk == 0) {
					printf("right. ");
				} else {
					printf("wrong. ");
				}

				MakeEmptyStack(s);

				for (i; i < cnt; i++) {
					printf("%c ", out[i]);
				}
				printf("\n");
			
				break;
			} else if (input == '(') {
				Push(input, s);
			} else if (input == ')') {
				while (1) {
					char ch = Pop(s);

					if (ch == '(') { 
						break; 
					} else if (ch == '\n') {
						chk = 1;
						break;
					} else {
						out[cnt] = ch;
						cnt++;
					}
				}
			} else {
				if (chk != 1) {
					if (s->top == -1) {
						out[cnt] = input;
						cnt++;
					} else {
						Push(input, s);
					}
				}
			}
		}
		DeleteStack(s);
	}
	return 0;
}

Stack CreateStack () {
	Stack s = (Stack)malloc(sizeof(stack));

	s->size = arraySize;
	s->top = -1;
	s->array = (char *)malloc(sizeof(char) * arraySize);

	return s;
}

Stack MakeEmptyStack (Stack s) {
	int i;

	s->top = -1;
	
	for (i = 0; i < sizeof(s->array); i++) {
		s->array[i] = NULL;
	}

	return s;
}

int IsEmpty (Stack s) {
	if (s->top == -1) {
		return 1;
	} else {
		return 0;
	}
}

void Push (char x, Stack s) {
	s->top++;
	s->array[s->top] = x;
}

char Pop (Stack s) {
	if (IsEmpty(s) == 1) {
		return '\n';
	} else {
		char ch;

		ch = s->array[s->top];
		s->array[s->top] = '\n';
		s->top--;
		return ch;
	}
}

void DeleteStack (Stack s) {
	free(s);
}