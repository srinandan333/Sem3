struct comp
{    
	char name[20];
	int age;  
	int morb;	          
};

struct node
{
	struct comp c;
	struct node *link;
};

struct pq
{
	struct node *head;
};

void init(struct pq* p);
void disp(struct pq *p);
void enqueue(struct pq* p,struct comp *c);
void dequeue(struct pq* p);
void display(const struct pq* p);
