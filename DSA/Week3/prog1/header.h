typedef struct Node
{
	char name[20];
	char ph_no[20];
	char address[50];
	char area[10];
	struct Node *prev;
	struct Node *next;
}node;
typedef struct List
{
	node *head;
	node *tail;
	int no_of_nodes;
}list;
void init(list *p);
void dinit(list *p);
void display(list *p);
void ordered_insert(list *p,char name[20],char ph_no[20],char address[50],char area[10]);



