#include <stdio.h>
void repeat_message( int n)
{
int i ;
for(i=0 ; i <= n ; i++)
{
printf("%d : hello,world.\n ",i);
}
}
int main ()
{
repeat_message(10);
return 0;
}
