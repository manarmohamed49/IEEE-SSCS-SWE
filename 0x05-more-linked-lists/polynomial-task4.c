#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Term {
    int coeff;
    int exp;
    struct Term* next;
} Term;


Term *A = NULL, *B = NULL, *C = NULL, *R = NULL;


Term* createTerm(int coeff, int exp) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}


void insertTerm(Term** poly, int coeff, int exp) {
    Term* newTerm = createTerm(coeff, exp);


    if (*poly == NULL || (*poly)->exp < exp) {
        newTerm->next = *poly;
        *poly = newTerm;
    } else {
        Term* current = *poly;

        while (current->next && current->next->exp > exp) {
            current = current->next;
        }


        if (current->next && current->next->exp == exp) {
            current->next->coeff = coeff;
        } else {

            newTerm->next = current->next;
            current->next = newTerm;
        }
    }
}


void clearPolynomial(Term **poly) {
    Term *temp;
    while (*poly) {
        temp = *poly;
        *poly = (*poly)->next;
        free(temp);
    }
}


void setPolynomial(char poly, int terms[][2], int termCount) {
    Term **target = NULL;


    switch (poly) {
        case 'A': target = &A; break;
        case 'B': target = &B; break;
        case 'C': target = &C; break;
        default:
            printf("Unknown polynomial %c\n", poly);
            return;
    }


    clearPolynomial(target);


    for (int i = 0; i < termCount; ++i) {
        insertTerm(target, terms[i][0], terms[i][1]);
    }
}


void printPolynomial(Term *poly) {
    if (!poly) {
        printf("0\n");
        return;
    }

    Term *current = poly;
    while (current) {
        if (current != poly && current->coeff > 0)
            printf(" + ");

        if (current->exp == 0)
            printf("%d", current->coeff);
        else if (current->exp == 1)
            printf("%dx", current->coeff);
        else
            printf("%dx^%d", current->coeff, current->exp);

        current = current->next;
    }
    printf("\n");
}
void evaluatePolynomial(char poly, float x) {
    Term *target = NULL;
    switch (poly) {
        case 'A': target = A; break;
        case 'B': target = B; break;
        case 'C': target = C; break;
        case 'R': target = R; break;
        default:
            printf("Unknown polynomial %c\n", poly);
            return;
    }

    float result = 0.0;
    while (target) {
        result += target->coeff * pow(x, target->exp);
        target = target->next;
    }
printf("Result = %.1f\n", result);
}
int main() {
    int termsA[][2] = {{3,2},{2,1},{1,0}};
    setPolynomial('A', termsA, 3);
    evaluatePolynomial('A', 2.0);
    return 0;
}
