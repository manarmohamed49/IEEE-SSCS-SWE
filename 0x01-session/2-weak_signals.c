#include <stdio.h>
int is_strong_signal(int strength)
{
if ( strength > 50)
{
return 1;
}
else 
{
return 0;
}
}
void check_signal(int strength)
{
if (is_strong_signal(strength))
    {
        printf("Strong signal detected.\n");
    }
    else
    {
        printf("No signal detected.\n");
    }
}
int main ()
{
check_signal(40);
check_signal(50);
check_signal(30);
check_signal(70);
return 0;
}
