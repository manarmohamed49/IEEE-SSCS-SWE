#include <stdio.h>
struct Being
{
char *name;
int age;
float energy_level;
};
void print_being(struct Being *b)
{
if (b==NULL)
return;
printf("name: %s, age:%d,energy : %.2f \n ",b->name, b->age, b->energy_level);
}
int main ()
{
struct Being alien ={"manar",21 , 87.45};
print_being(&alien);
return 0;
}

