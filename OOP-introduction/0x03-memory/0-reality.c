#include <stdio.h>

void status(int n)
{
if ( n > 0)
printf("positive\n");
if ( n < 0)
printf("negative\n");
if ( n = 0)
printf("zero\n");
}
int main() {
void (*ptr)(int);
ptr= status;
int number;
printf("enter the num:");
scanf("%d" , &number);
ptr(number);
return 0;
}
