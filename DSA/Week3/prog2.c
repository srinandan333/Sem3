#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct department
{
char name[20];
int number;
}dept;

typedef struct node
{
char ssn[10];
char name[20];
dept* dpt;
char designation[10];
int salary;
int phone_number;
int age;
struct node* prev, *next;
}node;

typedef struct employees
{
node* head;
}emp;

void init(emp* ptr)
{
  ptr->head=NULL;
}

void insert_f(emp* ptr, char* ssn, char* name, int ph, char* des, char* dpt_name, int age, int sal, int dept_num)
{
node* temp= (node*) malloc(sizeof(node));
temp->dpt= (dept*) malloc(sizeof(dept));
strcpy(temp->ssn,ssn);
strcpy(temp->name,name);
strcpy(temp->dpt->name,dpt_name);
temp->dpt->number=dept_num;
temp->salary=sal;
temp->phone_number=ph;
temp->age=age;
strcpy(temp->designation,des);
temp->prev=NULL;
temp->next=NULL;
if(ptr->head==NULL)
{
  ptr->head=temp;
  return;
}
node* p=ptr->head;
temp->next=ptr->head;
p->prev=temp;
ptr->head=temp;
}

void disp(const emp* ptr)
{
if(ptr->head==NULL)
{
  printf("no data to display\n");
  return;
}
node* p=ptr->head;
printf("\nDetails of employees:\n");
while(p!=NULL)
{
  printf("%s \t %s \t %s \t %d \t %s \t %d \t %d \t %d \n",p->ssn,p->name,p->dpt->name,p->dpt->number,p->designation, p->phone_number, p->salary, p->age);
  p=p->next;
}
printf("\n");
}

void delete_above_58(emp* ptr)
{
node* p1=ptr->head;
if(ptr->head==NULL)
{
  printf("no nodes in list\n");
  return;
}
if(p1->age>58)
{
  ptr->head=p1->next;
  p1->prev=NULL;
return;
}

while(p1!=NULL)
{
if(p1->age>58 && p1->next!=NULL)
 {
  p1->prev->next=p1->next;
  p1->next->prev=p1->prev;
 }
 else if(p1->age>58 && p1->next==NULL)
 {
  p1->prev->next=NULL; 
 }
 p1=p1->next;
}
}

void display_dept(emp* ptr, char *dept_name)
{
if(ptr->head==NULL)
{
  printf("\nno data to display\n");
  return;
}
node* p=ptr->head;
while(p!=NULL)
{
  if(strcmp(p->dpt->name,dept_name)==0)
{
    printf("%s \t %s \t %s \t %d \t %s \t %d \t %d \t %d \n",p->ssn,p->name,p->dpt->name,p->dpt->number,p->designation, p->phone_number, p->salary, p->age);
}
  p=p->next;
}
printf("\n");
}

int main()
{
emp e1;
init(&e1);
int num,sal,ph,age,dptn;
char n[20],ssn[20],des[10],dpt_name[20];
printf("Enter number of employees: ");
scanf("%d",&num);
for(int i=0;i<num;i++)
{
  printf("\nEnter ssn :");
  scanf("%s",ssn);
  printf("Enter employee name: ");
  scanf("%s",n);
  printf("Enter department name: ");
  scanf("%s",dpt_name);
  printf("Enter department number: ");
  scanf("%d",&dptn);
  printf("Enter designation: ");
  scanf("%s",des);
  printf("Enter salary: ");
  scanf("%d",&sal);
  printf("Enter phone number: ");
  scanf("%d",&ph);
  printf("Enter age: ");
  scanf("%d",&age);
if(age<0 || age>100)
{
    printf("Enter valid age\n");
    return 0;
}
else
{
    insert_f(&e1,ssn,n,ph,des,dpt_name,age,sal,dptn);
    printf("Node inserted\n");
}
}

disp(&e1);
char dept[20];
int opt;
while(1)
{
printf("\n1. To delete records of employees with age greater than 58\n2. To find details of employees working in a department\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
	delete_above_58(&e1);
	printf("(The nodes after deleting the records of employees above the age of 58)\n");
	disp(&e1);
	break;
case 2:
	printf("enter department name: ");
	scanf("%s",dept);
	printf("the details of employees working in %s department: \n");
	display_dept(&e1,dept);
	break;
default:
	exit(0);
}
}
return 0;
}