#include <stdio.h>
int manual_sizeof()
{
int arr[2];
char *p1 = (char *)&arr[0];
char *p2 = (char *)&arr[1];
return (int)(p2 - p1);
}
int main (){
int size = manual_sizeof();
printf("manual size : %d bytes\n" , size);
return 0;
}
