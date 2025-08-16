#include <stdio.h>
#include <stdlib.h>
int global_variable =100;
int main()
{
int local_variable = 200;
 int *heap_variable = malloc(sizeof(int));
if (heap_variable == NULL)
{
return 1;
}
*heap_variable = 300;
char *str_literal = "hello";
 printf("(%p : data) -> %d\n", (void *)&global_variable, global_variable);
printf("(%p : stack) -> %d\n", (void *)&local_variable, local_variable);
    printf("(%p : heap) -> %d\n", (void *)heap_variable, *heap_variable);
    printf("(%p : rodata) -> %s\n", (void *)str_literal, str_literal);

free(heap_variable);

    return 0;
}
