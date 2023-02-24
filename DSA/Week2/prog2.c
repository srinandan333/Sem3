#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int key;
    struct node *link;
};
 
void del_alt(struct node *head)
{
    if (head == NULL)
        return;
    struct node *prev = head;
    struct node *node = head->link;
    while (prev != NULL && node != NULL)
    {
        prev->link = node->link;
        free(node);
        prev = prev->link;
        if (prev != NULL)
            node = prev->link;
    }
}

void next(struct node** head_ref, int new_key)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->key  = new_key;
    new_node->link = (*head_ref);
    (*head_ref)    = new_node;
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->key);
        node = node->link;
    }
}

int main()
{   
    struct node* head = NULL;
    int n;
    int i;
    printf("Enter number of elements: \n");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        next(&head,a[i]);
    }
    printf(" \n List before deleting: \n");
    printList(head);
    del_alt(head);
    printf(" \n List after deleting: \n");
    printList(head);
    return 0;
}