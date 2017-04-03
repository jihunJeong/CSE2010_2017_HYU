#include <stdio.h>
#include <stdlib.h>

typedef struct node * pNode;
typedef pNode List;
typedef pNode Node;

typedef struct node {
    int value;
    Node next;
}node;

void Insert (List list, int num, Node prev_n, int fnum);
void Delete (List list, int num, Node prev_n);
Node FindPrev (List list, int num);
void Find (List list, int num, Node prev_n);
void Show (List list);
void DeleteList (List list);

int main ()
{
    List list = (List)malloc(sizeof(node));
    list->value = 0;
    
    while (1) {
        char init;
        int num, fnum;
        
        scanf("%c", &init);
        
        switch (init) {
            case 105:
                scanf("%d %d", &num, &fnum);
                Node prev_n1 = FindPrev(list, fnum);
                Insert(list, num, prev_n1, fnum);
                break;
            case 100:
                scanf("%d", &num);
                Node prev_n2 = FindPrev(list, num);
                Delete(list, num, prev_n2);
                break;
            case 102:
                scanf("%d", &num);
                Node prev_n3 = FindPrev(list, num);
                Find(list, num, prev_n3);
                break;
            case 115:
                Show(list);
                break;
            case 101:
                DeleteList(list);
                return 0;
        }
    }
}

void Insert (List list, int num, Node prev_n, int fnum) {
    Node n = prev_n->next;
    
    if (fnum == 0) {
        List var = (List)malloc(sizeof(node));
        var->next = list->next;
        list->next = var;
        var->value = num;
    } else if (n != NULL) {
        List var = (List)malloc(sizeof(node));
        var->next = n->next;
        n->next = var;
        var->value = num;
    } else {
        printf("Insert error. The %d isn't in the list.\n", fnum);
    }
}

void Delete (List list, int num, Node prev_n) {
    if (prev_n->next != NULL) {
        Node pnode = prev_n->next;
        prev_n->next = pnode->next;
        free(pnode);
    } else {
        printf("Delete error. The %d isn't in the list.\n", num);
    }
}

Node FindPrev (List list, int fnum) {
    Node pnode = list;
    Node cnode = pnode->next;

    if (fnum == 0) {
        return list;
    }

    while (cnode != NULL) {
        if (cnode->value == fnum) {
            break;
        }
        
        pnode = pnode->next;
        cnode = pnode->next;
    }

    return pnode;
}

void Find (List list, int num, Node prev_n) {
    if (prev_n->next != NULL) {
        if (prev_n->value == 0) {
            printf("The %d is next of The header.\n", num);
        } else {
            printf("The %d is next of The %d.\n", num, prev_n->value);
        }
    } else {
        printf("Find error. The %d isn't in the list\n", num);
    }
}

void Show (List list) {
    Node pnode = list->next;
    
    while (pnode != NULL) {
        printf("%d ", pnode->value);
        pnode = pnode->next;
    }

    printf("\n");
}

void DeleteList (List list) {
    while (list != NULL) {
        Node pnode = list;
        list = list->next;
        free (pnode);
    }
}
