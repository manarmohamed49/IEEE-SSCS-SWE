#include <stdio.h>
void swap(int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}
int main()
{

int x = 5;
int y =10;

printf("before swapping: x=%d , y=%d\n",x,y);
swap(&x , &y);
printf("after  swapping: x=%d , y=%d\n",x,y);
return 0;
}
