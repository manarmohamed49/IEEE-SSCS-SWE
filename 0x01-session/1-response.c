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
if(is_response_detected(30))
printf("strenth %d : response detected\n", strength);
else
printf("strenth %d :no  response detected\n", strength);
if(is_response_detected(50))
printf("strenth %d : response detected\n", strength);
else 
printf("strenth %d :no  response detected\n", strength);
if(is_response_detected(80))
printf("strenth %d : response detected\n", strength);
else 
printf("strenth %d :no  response detected\n", strength);
if(is_response_detected(50))
printf("strenth %d : response detected\n", strength);
else 
printf("strenth %d :no  response detected\n", strength);
return 0;
}
