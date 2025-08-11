#include <stdio.h>
int main ()
{
int signal =98;
int *ptr = &signal;
printf("%p\n",ptr);
printf("%d\n" , *ptr);
return 0;
}
