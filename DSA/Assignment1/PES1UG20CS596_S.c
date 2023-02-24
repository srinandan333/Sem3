#include <stdio.h>
#include <stdlib.h>
#include "PES1UG20CS596_H.h"

void push(node_t *stack_t[], node_t *ele)
{
    top++;
    stack_t[top] = ele;
}

node_t *pop(node_t *stack_t[])
{
    top--;
    return stack_t[top + 1];
}

node_t *read(int *x0, int *y0, int *xf, int *yf)
{
    int x1, y1, x2, y2;
    FILE *fp = fopen("input.txt", "r");
    fscanf(fp, "%d %d", &x1, &y1);
    fscanf(fp, "%d %d", &x2, &y2);
    *x0 = x1;
    *y0 = y1;
    *xf = x2;
    *yf = y2;
    node_t *p = (node_t*)malloc(sizeof(node_t));
    p->down = NULL;
    p->right = NULL;
    p->union_t.entry_t.row = x2 - x1;
    p->union_t.entry_t.col = y2 - y1;
    p->union_t.entry_t.info = 0;
    p->union_t.next = NULL;
    for (int i = x1; i <= x2; i++)
    {
        node_t *q = (node_t*)malloc(sizeof(node_t));
        q->down = NULL;
        q->right = q;
        q->union_t.next = NULL;
        if (i - x1 == 0)
        {
            p->down = q;
            q->down = p;
        }
        else
        {
            node_t *r;
            r = p;
            while (r->down != p)
            {
                r = r->down;
            }
            r->down = q;
            q->down = p;
        }
    }
    for (int j = y1; j <= y2; j++)
    {
        node_t *q = (node_t*)malloc(sizeof(node_t));
        q->down = q;
        q->right = NULL;
        q->union_t.next = NULL;
        if (j - y1 == 0)
        {
            p->right = q;
            q->union_t.next = p;
        }
        else
        {
            node_t *r;
            r = p->right;
            while (r->union_t.next != p)
            {
                r = r->union_t.next;
            }
            r->union_t.next = q;
            q->union_t.next = p;
        }
    }
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            int a;
            fscanf(fp, "%d", &a);
            if (a == 0)
            {
                node_t *s = (node_t*)malloc(sizeof(node_t));
                s->down = NULL;
                s->right = NULL;
                s->union_t.entry_t.row = i;
                s->union_t.entry_t.col = j;
                s->union_t.entry_t.info = 0;
                p->union_t.entry_t.info += 1;
                node_t *f;
                f = p;
                for (int l = 0; l < j + 1; l++)
                {
                    if (f == p)
                    {
                        f = f->right;
                    }
                    else
                    {
                        f = f->union_t.next;
                    }
                }
                node_t *t;
                t = f;
                while (t->down != f)
                {
                    t = t->down;
                }
                t->down = s;
                s->down = f;
                node_t *y;
                y = p;
                for (int l = 0; l < i + 1; l++)
                {
                    y = y->down;
                }
                node_t *z;
                z = y;
                while (z->right != y)
                {
                    z = z->right;
                }
                z->right = s;
                s->right = y;
            }
        }
    }
    int mn = 0;
    node_t *u = p->down;
    node_t *w = p->down;
    fclose(fp);
    return p;
}

void store(node_t *stack_t[], int x2, int y2, int key)
{
    FILE *f = fopen("output.txt", "w");
    if (key == 1)
    {
        for (int h = 1; h <= top; h++)
        {
            fprintf(f, " %d %d ", stack_t[h]->union_t.entry_t.row, stack_t[h]->union_t.entry_t.col);
            fprintf(f, "\n");
        }
        fprintf(f, " %d %d ", x2, y2);
    }
    else
    {
        fprintf(f, "%d", -1);
    }
    fclose(f);
}

void search(node_t *stack_t[], node_t *p, int x1, int y1, int x2, int y2)
{
    int key = 1;
    node_t *sx = p->down->right;
    node_t *sy = p->right;
    node_t *sz = p->down;
    push(stack_t, sx);
    while (sx->union_t.entry_t.row != x2 || sx->union_t.entry_t.col != y2)
    {
        if (sx->right != sz && (sx->right->union_t.entry_t.col == sx->union_t.entry_t.col + 1))
        {
            push(stack_t, sx);
            sx = sx->right;
            sy = sy->union_t.next;
        }
        else if (sx->down != sy && (sx->down->union_t.entry_t.row == sx->union_t.entry_t.row + 1))
        {
            push(stack_t, sx);
            sx = sx->down;
            sz = sz->down;
        }
        else
        {
            node_t *sxy = pop(stack_t);
            while (top != -1 && (!((sxy->right->union_t.entry_t.info == 0 && (sxy->right->union_t.entry_t.col == sxy->union_t.entry_t.col + 1)) && (sxy->down->union_t.entry_t.info == 0 && (sxy->down->union_t.entry_t.row == sxy->union_t.entry_t.row + 1)))))
            {
                sx = sxy;
                sxy = pop(stack_t);
            }
            if (top == -1)
            {
                printf("\nError\n");
                key = 0;
                store(stack_t, x2, y2, key);
                return;
            }
            else
            {
                if (sx == sxy->down)
                {
                    printf("\nError\n");
                    key = 0;
                    store(stack_t, x2, y2, key);
                    return;
                }
                else
                {
                    sx = sxy;
                    int gh = 0;
                    sz = p->down;
                    while (gh <= sx->union_t.entry_t.row)
                    {
                        gh++;
                        sz = sz->down;
                    }
                    int ij = 0;
                    sy = p->right;
                    while (ij <= sx->union_t.entry_t.col)
                    {
                        ij++;
                        sy = sy->union_t.next;
                    }
                    push(stack_t, sx);
                }
            }
            sx = sx->down;
        }
    }
    store(stack_t, x2, y2, key);
}
