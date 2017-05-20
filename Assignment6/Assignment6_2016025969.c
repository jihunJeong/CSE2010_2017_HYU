#include <stdio.h>
#include <stdlib.h>

/* quicksort
int left�� int left�� �� ����, �����ʿ� ���� ��Ÿ��
pivot���� �񱳸� ���� do while �� ����
�� ���� swap ����
ũ�� ������� ������ �Ѵ�.
��� �Լ��� �ٽ� ����. quick sort �Լ�
*/

typedef struct element {
	int key;
}element;

void QuickSort(element list[], int left, int right);
void Swap(element* a, element* b, element* temp);

int main()
{
	element list[1000];
	int num, i;
	int grade = 1, p_grade = 1;
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		int score;
		scanf("%d", &score);
		list[i].key = score;
	}

	QuickSort(list, 0, num - 1);

	for (i = num - 1; i >= 0; i--) {
		if (i != num - 1 && list[i].key != list[i + 1].key) {
			grade = p_grade;
		}

		printf("%d %d\n", list[i].key, grade);

		p_grade++;
	}

	return 0;
}

void QuickSort(element list[], int left, int right) {
	int pivot, i, j;
	element temp;
	temp.key = 0;

	if (left < right) {
		i = left; j = right + 1;
		pivot = list[left].key;

		do {
			do {
				i++;
			} while (list[i].key < pivot);

			do {
				j--;
			} while (list[j].key > pivot);

			if (i < j) {
				Swap(&list[i], &list[j], &temp);
			}
		} while (i < j);

		Swap(&list[left], &list[j], &temp);
		QuickSort(list, left, j - 1);
		QuickSort(list, j + 1, right);
	}
}

void Swap(element* a, element* b, element* temp) {
	temp->key = a->key;
	a->key = b->key;
	b->key = temp->key;
}