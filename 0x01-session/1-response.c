#include <stdio.h>
 int is_response_detected(int strength)
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
int main()
{
int strength;
printf("enter signal strength: ");
    scanf("%d", &strength);
if (is_response_detected(strength))
        printf(" %d: Response detected \n", strength);
    else
        printf(" %d: No response \n", strength);

    return 0;
}
