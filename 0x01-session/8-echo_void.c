#include <stdio.h>
void echo(int n)
{
if( n <=0)
return ;
else
printf("%d:echo \n",n);
echo(n-1);
}
int main ()
{
echo(6);
return 0;
}
