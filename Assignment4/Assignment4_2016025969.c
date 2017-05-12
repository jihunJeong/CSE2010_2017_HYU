#include <stdio.h>
#include <stdlib.h>

typedef struct node * Node;
typedef struct node * Tree;

struct node {
	int value;
    Node leftChild;
	Node rightChild;
    Node parent;
};

Tree CreateTree();
int IsEmpty(Tree T);
Node Search(Tree T, int key);
Node SearchMin(Tree T);
void DeleteNode(Tree T, int key);
Node InsertNode(Tree T, int key);
void ShowAll(Tree T);
int GetHeight(Tree T);

int main()
{
	Tree T = NULL;
	while (1) {
		char ch;
		int input;

		scanf("%c", &ch);

		switch (ch) {
		case 'i':
			scanf("%d", &input);
			if (T == NULL) {
				T = CreateTree();
				T->value = input;
			} else {
				InsertNode(T, input);
			}
			break;
		case 'd':
			scanf("%d", &input);
			DeleteNode(T, input);
			break;
		case 'h':
			scanf("%d", &input);
            Node n = Search(T, input);
            int height = GetHeight(n) - 1;
            if (n == NULL) {
                printf("Not found\n");
            } else {
			    printf("The height of the node (%d) is %d\n", input, height);
            }
            break;
		case 's':
			ShowAll(T);
			printf("\n");
			break;
		case 'e':
			return 0;
		}
	}


}

Tree CreateTree() {
	Tree T = (Tree)malloc(sizeof(struct node));
	if (T == NULL) {
		printf("malloc error\n");
	}
	T->value;
	T->leftChild = NULL;
	T->rightChild = NULL;
    T->parent = NULL;
	return T;
}

int IsEmpty(Tree T) {
	if (T == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

Node Search(Tree T, int key) {
	if (T == NULL) {
		return NULL;
	}
	else if (key < T->value) {
		Search(T->leftChild, key);
	}
	else if (key > T->value) {
		Search(T->rightChild, key);
	}
	else {
		return T;
	}
}

Node SearchMin(Tree T) {
	if (T == NULL) {
		return NULL;
	}
	else if (T->leftChild == NULL) {
		return T;
	}
	else {
		return SearchMin(T->leftChild);
	}
}

void DeleteNode(Tree T, int key) {
	Tree dt = Search(T, key);
	Tree tmp = NULL;

	if (dt == NULL) {
		printf("Not found\n");
	} else if (dt->leftChild && dt->rightChild) {
        tmp = SearchMin(dt->rightChild);
        dt->value = tmp->value;
        DeleteNode(dt->rightChild, tmp->value);
	} else {
        if (dt->leftChild != NULL) {
            tmp = dt->leftChild;
        } else if (dt->rightChild != NULL) {
            tmp = dt->rightChild;
        }

        if (dt->parent != NULL) {
            if (dt->parent->leftChild == dt) {
                dt->parent->leftChild = tmp;
            } else {
                dt->parent->rightChild = tmp;
            }
        }

        free(dt);
      
	}
}

Tree InsertNode(Tree T, int key) {
	if (T == NULL) {
		T = CreateTree();
		T->value = key;
	}
	else if (key < T->value) {
		T->leftChild = InsertNode(T->leftChild, key);
        T->leftChild->parent = T;
	}
	else if (key > T->value) {
		T->rightChild = InsertNode(T->rightChild, key);
        T->rightChild->parent = T;
	}

	return T;
}

void ShowAll(Tree T) {
	if (T) {
		ShowAll(T->leftChild);
		printf("%d ", T->value);
		ShowAll(T->rightChild);
	}
}

int GetHeight(Tree T) {
    int left = T->leftChild ? GetHeight(T->leftChild) : 0;
    int right = T->rightChild ? GetHeight(T->rightChild) : 0;
    return (left > right ? left : right) + 1;
}
