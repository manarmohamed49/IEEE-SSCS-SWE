#include <stdio.h>
#include <stdlib.h>
int countdigits( long long n)
{
n = llabs(n);
if ( n < 10)
 return 1;
return 1 + countdigits( n / 10);
}
int sumdigits(long long n)
{
 n =llabs(n);
int digits = countdigits(n);
printf("num of digits : %d" , digits);

int recurcivesum(long long num){
if( num < 10)
return num ;
return (num % 10) + recurcivesum(num / 10);
}
return  recurcivesum(n);
}
int main() {
    long long int number;
    printf("enter the number: ");
    scanf("%lld", &number);

    int sum = sumdigits(number);
    printf("sum of digits: %d\n", sum);

    return 0;
}
