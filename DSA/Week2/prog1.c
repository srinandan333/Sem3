#include <stdio.h>
#include <stdlib.h>
 
struct node 
{
    int key;
    struct node* link;
};
 
void swap(struct node** head_ref, int x, int y)
{
    if (x == y)
        return;
    struct node *prevX = NULL, *presX = *head_ref;
    while (presX && presX->key != x) 
    {
        prevX = presX;
        presX = presX->link;
    }
    struct node *prevY = NULL, *presY = *head_ref;
    while (presY && presY->key != y) 
    {
        prevY = presY;
        presY = presY->link;
    }
    if (presX == NULL || presY == NULL)
        return;
    if (prevX != NULL)
        prevX->link = presY;
    else 
        *head_ref = presY;
    if (prevY != NULL)
        prevY->link = presX;
    else 
        *head_ref = presX;
    struct node* temp = presY->link;
    presY->link = presX->link;
    presX->link = temp;
}
 
void next(struct node** head_ref, int new_key)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = new_key;
    new_node->link = (*head_ref);
    (*head_ref) = new_node;
}
 
void printList(struct node* node)
{
    while (node != NULL) 
    {
        printf("%d ", node->key);
        node = node->link;
    }
}

int main()
{
    struct node* start = NULL;
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
        next(&start,a[i]);
    }
    printf(" \n Linked list before swapping:\n ");
    printList(start);
    swap(&start, 4, 3);
    printf(" \n Linked list after swapping:\n ");
    printList(start);
    return 0;
}