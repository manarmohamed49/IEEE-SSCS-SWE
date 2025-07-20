#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coeff;
    int exp;
    struct Term* next;
} Term;

Term *A = NULL;

void addTerm(Term **poly, int coeff, int exp) {
    Term *newTerm = malloc(sizeof(Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = *poly;
    *poly = newTerm;
}

void printPolynomial(Term *poly) {
    while (poly) {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next) printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

void clearPolynomial(char poly) {
    Term **target;
    switch (poly) {
        case 'A': target = &A; break;
        default: return;
    }
    Term *current = *target;
    while (current != NULL) {
        Term *temp = current;
        current = current->next;
        free(temp);
    }
    *target = NULL;
    printf("Polynomial %c has been cleared.\n", poly);
}

int main() {
    addTerm(&A, 3, 2);
    addTerm(&A, 2, 1);
    addTerm(&A, 1, 0);

    printf("before clearing: ");
    printPolynomial(A);

    clearPolynomial('A');

    printf("after clearing: ");
    printPolynomial(A); 

    return 0;
}
