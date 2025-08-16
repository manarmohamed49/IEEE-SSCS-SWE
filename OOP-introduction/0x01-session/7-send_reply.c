#include <stdio.h>
char *get_reply()
{
return "hello ieee";
}
int main ()
{
const char *message = get_reply();
printf("%s\n" , message);
return 0;
}
