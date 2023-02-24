#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct hashtable
{
    long long phone;
    char name[30];
    struct hashtable *link;
} node_t;

void init(node_t *hash[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        hash[i] = NULL;
    }
}

void insert(node_t *hash[MAX], long long phone, char name[30])
{
    int index = phone % MAX;
    node_t *temp = malloc(sizeof(node_t));
    temp->phone = phone;
    strcpy(temp->name, name);
    temp->link = NULL;
    if (hash[index] == NULL)
    {
        hash[index] = temp;
        return;
    }
    node_t *pres = hash[index];
    while (pres->link != NULL)
    pres = pres->link;
    pres->link = temp;
}

int delete (node_t *hash[MAX], long long phone)
{
    int index = phone % MAX;
    node_t *pres = hash[index];
    node_t *prev = NULL;
    while (pres != NULL && pres->phone != phone)
    {
        prev = pres;
        pres = pres->link;
    }
    if (pres != NULL)
    {
        if (prev == NULL)
        {
            hash[index] = pres->link;
        }
        else
        {
            prev->link = pres->link;
        }
        free(pres);
        return 1;
    }
    return 0;
}

int search(node_t *hash[MAX], long long phone, char name[30])
{
    int index = phone % MAX;
    node_t *pres = hash[index];
    while (pres != NULL)
    {
        if (pres->phone == phone)
        {
            strcpy(name, pres->name);
            return 1;
        }
        pres = pres->link;
    }
    return 0;
}

void display(node_t *hash[MAX])
{
    node_t *pres;
    for (int i = 0; i < MAX; i++)
    {
        pres = hash[i];
        printf("%d => ", i);
        while (pres != NULL)
        {
            printf("Phone:%lld,Name:%s=>", pres->phone, pres->name);
            pres = pres->link;
        }
        printf("NULL\n");
    }
}

void destroy(node_t *hash[MAX])
{
    node_t *pres, *prev;
    for (int i = 0; i < MAX; i++)
    {
        pres = hash[i];
        while (pres != NULL)
        {
            prev = pres;
            pres = pres->link;
            free(prev);
        }
        hash[i] = NULL;
    }
}

int main()
{
    node_t *hash[MAX];
    init(hash);
    int choice;
    long long phone;
    char name[30];
    
    printf("1. Insert\t2. Delete\t3. Search\t4. Display\t5. Exit\n");
    printf("Enter choice:");
    scanf("%d", &choice);
    do
    {
        switch (choice)
        {
            case 1:
                printf("Enter phone number:\n");
                scanf("%lld", &phone);
                printf("Enter your name:\n");
                scanf("%s", name);
                insert(hash, phone, name);
                break;
            case 2:
                printf("Enter phone number:\n");
                scanf("%lld", &phone);
                if (delete (hash, phone))
                {
                    printf("Record with phone %lld deleted\n", phone);
                }
                else
                {
                    printf("Record not found\n");
                }
                break;
            case 3:
                printf("Enter phone number:\n");
                scanf("%lld", &phone);
                if (search(hash, phone, name))
                {
                    printf("Record found\nPhone number - %lld,Name:%s\n", phone, name);
                }
                else
                {
                    printf("Record not found\n");
                }
                break;
            case 4:
                display(hash);
                break;
            case 5:
                destroy(hash);
            return 0;
        }
        printf("Enter choice:");
        scanf("%d", &choice);
    } while (choice);
    destroy(hash);
}