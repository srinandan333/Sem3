typedef  struct  node
{
    int coeff;
    int  powx; 
    int  powy;
    struct node *next;
}node_t;

typedef  struct  list
{
    node_t  *head;
}list_t;

void  disp(list_t  *);
void  add_pol(list_t  *res,list_t  *p1,list_t  *p2);
