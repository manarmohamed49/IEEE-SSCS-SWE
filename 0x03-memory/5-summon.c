#include <stdio.h>
#include <stdlib.h>

int *summon_allies(int *allies, int n);

int main()
{
    int *allies = NULL;
    int n;

    printf("how many allies? ");
    scanf("%d", &n);

    allies = summon_allies(allies, n);
    if (allies == NULL)
    {
        printf("Cannot summon allies.\n");
        return 1;
    }

    printf("allies summoned:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", allies[i]);
    }
    printf("\n");

    free(allies);
    return 0;
}

int *summon_allies(int *allies, int n)
{
    allies = malloc(n * sizeof(int));
    if (allies == NULL)
    {
        printf("memory allocation failed.\n");
        return NULL;
    }

    printf("Enter %d allies:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("> ");
        scanf("%d", &allies[i]);
    }

    return allies;
}

