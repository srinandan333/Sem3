#include <stdio.h>
#include <stdlib.h>
#include "PES1UG20CS596_H.h"

int main()
{
    top = -1;
    int i1, y1, x2, y2;
    node_t *p;
    p = read(&i1, &y1, &x2, &y2);
    node_t *stack_t[30];
    search(stack_t, p, i1, y1, x2, y2);
    FILE *f = fopen("output.txt", "r");
    while (!feof(f))
    {
        char a;
        fscanf(f, "%c", &a);
        printf("%c", a);
    }
    fclose(f);
    return 0;
}
