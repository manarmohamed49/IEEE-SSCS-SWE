#include <stdio.h>

void access_one()
{
    
    static int counter = 0;
    counter++;
    printf("access_one called %d times\n", counter);
}

void access_two()
{
    static int counter = 0;
    counter++;
printf("access_two called %d times\n", counter);
}
int main()
{
    for (int i = 0; i < 3; i++) {
        access_one();
        if (i < 2) {
            access_two();
        }
    }

    return 0;
}
