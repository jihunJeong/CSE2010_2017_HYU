#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct employee {
    char name[10];
    int age;
    int salary;
    char department[20];
} Employee;

void Insert (Employee *arr, int arr_cnt);
void Delete (Employee *arr, char *name, int arr_cnt);
int Find (Employee *arr, char *name, int arr_cnt);
void Inform (Employee *arr, char *name, int arr_cnt);
int AvgBenefit (Employee *arr, char *department, int arr_cnt);

int main () 
{
    int num, chk = 0;
    char set[10];
    char junk;

    scanf("%s", set);
    scanf("%d", &num);
    junk = getchar();

    Employee *arr = (Employee *)malloc(sizeof(Employee) * num);
    
    do {
        char kind[10];
        char ch, junk;

        ch = getchar();

        int chk = ch;

        if (chk != 10) {
            scanf("%s", kind);
        }

        if (!strcmp(kind, "nsert") && ch == 'i') {
            Insert(arr, num);
        } else if (!strcmp(kind, "elete") && ch == 'd') {
            char name[10];
            scanf("%s", name);
            Delete(arr, name, num);
        } else if (!strcmp(kind, "ind") && ch == 'f') {
            char name[10];
            scanf("%s", name);
            Find(arr, name, num);
        } else if (!strcmp(kind, "nform") && ch == 'i') {
            char name[10];
            scanf("%s", name);
            Inform(arr, name, num);
        } else if (!strcmp(kind, "vg") && ch == 'a') {
            char department[20];
            scanf("%s", department);
            printf("%d\n", AvgBenefit(arr, department, num));
        } else if (chk == 10) {
            break;
        }

        junk = getchar();
    
    } while (1);

    free(arr);

    return 0;
}

void Insert (Employee *arr, int arr_cnt)
{
    char name[10], department[20];
    int age, salary, cnt = 0, i = 0;

    scanf("%s", name);
    scanf("%d", &age);
    scanf("%d", &salary);
    scanf("%s", department);

    for(i; i < arr_cnt; i++) {
        if (!strcmp(arr[i].name, "\0")) {
            break;
        } else {
            cnt++;
        }
    }

    if (cnt == arr_cnt) {
        printf("Not enough space\n");
    } else {
        strcpy(arr[cnt].name, name);
        arr[cnt].age = age;
        arr[cnt].salary = salary;
        strcpy(arr[cnt].department, department);
    }
}

void Delete (Employee *arr, char *name, int arr_cnt)
{
    int cnt = 0, i = 0;
    
    for (i; i < arr_cnt; i++) {
        if (!strcmp(arr[i].name, name)) {
            *arr[i].name = '\0';
            arr[i].age = 0;
            arr[i].salary = 0;
            *arr[i].department = '\0';
            break;
        } else {
            cnt++;
        }
    }

    if (cnt == arr_cnt) {
        printf("Not found\n");
    }
}

int Find (Employee *arr, char *name, int arr_cnt)
{
    int cnt = 0, i = 0;
    
    for (i; i < arr_cnt; i++) {
        if (!strcmp(arr[i].name, name)) {
            printf("%d\n", i);
            break;
        } else {
            cnt++;
        }
    }

    if (cnt == arr_cnt) {
        printf("-1\n");
    }
}

void Inform (Employee *arr, char *name, int arr_cnt)
{
    int cnt = 0, i = 0;

    for (i; i < arr_cnt; i++) {
        if (!strcmp(arr[i].name, name)) {
            printf("%s ", arr[i].name);
            printf("%d ", arr[i].age);
            printf("%d ", arr[i].salary);
            printf("%s\n", arr[i].department);
        } else {
            cnt++;
        }
    }

    if (cnt == arr_cnt) {
        printf("Not found\n");
    }
}

int AvgBenefit (Employee *arr, char *department, int arr_cnt)
{
    int sum = 0, avg = 0, cnt = 0, i = 0;

    for (i; i < arr_cnt; i++) {
        if (!strcmp(arr[i].department, department)) {
            sum += arr[i].salary;
            cnt++;
        }
    }
   
    if (cnt == 0) {
        cnt++;
    }
    avg = sum / cnt;

    return avg;
}
