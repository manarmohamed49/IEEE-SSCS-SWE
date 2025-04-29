#include <stdio.h>
int signal_strength = 0;
void boost_signal(int n)
{
int signal_strength = 100;
printf("booster:signal strength=%d\n",n);
}
int main ()
{
 printf("before boost: signal strength = %d\n", signal_strength);

    boost_signal(75);

    printf("after boost: signal strength = %d\n", signal_strength);

    return 0;
}
