#include <stdio.h>
int sum_layers(int n)
{
if (n <= 0)
return 0;
else 
return n +  sum_layers(n - 1);
}
int main ()
{
int n ;
printf("enter the num of layers:");
scanf("%d" , &n);
printf("sum layers: %d\n",sum_layers( n ));
return 0;
}
