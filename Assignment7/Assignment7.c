#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 100000
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY (n) (!n)

typedef struct element {
	char name[20];
	int k_score;
	int m_score;
	int e_score;
}element;
element list[MAX_ELEMENTS];

element MakeElement();
void Adjust(element list[], int root, int n);
void HeapSort(element list[], int n);
void Swap(element *a, element *b);
int Priority(element a, element b);

int main ()
{
	int num, k_score, m_score, e_score;
	int n = 0, f_index = 0, i, m_index = 0, e_index;
	element item;
	char name[20];
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		item = MakeElement();
		list[++n] = item;
	}

	HeapSort(list, n);

    for (i = num; i > 0; i--) {
        printf("%s\n", list[i].name);
    }
}

element MakeElement() {
	int k_score, m_score, e_score;
	element item;
	char name[20];

	scanf("%s", name);
	scanf("%d %d %d", &k_score, &e_score, &m_score);
	strcpy(item.name, name);
	item.k_score = k_score;
	item.e_score = e_score;
	item.m_score = m_score;

	return item;
}


void Adjust(element list[], int root, int n) {
	int child = 2 * root;
	element rootkey = list[root];
	element temp = list[root];

	while (child <= n) {
		if (child < n && Priority(list[child], list[child + 1]) == 0) {
			child++;
		}
		if (Priority(rootkey, list[child]) == 1) {
			break;
		} else {
			list[child / 2] = list[child];
			child *= 2;
		}
	}
	list[child / 2] = temp;
}

void HeapSort(element list[], int n) {
	int i, j;
	element temp;

	for (i = n / 2; i > 0; i--)
		Adjust(list, i, n);
    for (i = n - 1; i > 0; i--) {
		Swap(&list[1], &list[i + 1]);
		Adjust(list, 1, i);
    }
}

void Swap(element *a, element *b) {
	element temp = *a;
	*a = *b;
	*b = temp;
}

int Priority(element a, element b) {
	if (a.k_score > b.k_score) {
		return 1;
	} else if (a.k_score == b.k_score) {
		if (a.e_score < b.e_score) {
			return 1;
		}
	}

	if (a.k_score == b.k_score && a.e_score == b.e_score) {
		if (a.m_score > b.m_score) {
			return 1;
		} else if (a.m_score == b.m_score) {
			if (strcmp(a.name, b.name) < 0) {
				return 1;
			}
		}

		return 0;
	}

	return 0;

}
