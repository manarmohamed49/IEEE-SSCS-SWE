
#include <stdio.h>
typedef enum {
INT , FLOAT , CHAR }
dataType;

void echo_data(void*data, dataType type)
{
if (type == INT )
printf("%d\n ", *((int *)data));
else if (type == FLOAT)
printf("%f \n ", *((float *)data));
else if (type ==  CHAR )
printf("%c \n " , *((char *)data));
else 
printf("unknown type\n");
}
int main()
{
    int i = 40;
    float f = 3.14;
    char c = 'M';
echo_data(&i, INT );
echo_data(&f ,  FLOAT);
echo_data(&c ,  CHAR );
return 0;
}
