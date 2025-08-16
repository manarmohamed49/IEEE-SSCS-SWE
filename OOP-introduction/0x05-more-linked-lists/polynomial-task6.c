#include <stdio.h>
#include <stdlib.h>

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
    if (coeff == 0) return;

    Term* newTerm = createTerm(coeff, exp);

    if (*poly == NULL || (*poly)->exp < exp) {
        newTerm->next = *poly;
        *poly = newTerm;
    } else {
        Term* current = *poly;
        Term* prev = NULL;

        while (current && current->exp > exp) {
            prev = current;
            current = current->next;
        }

        if (current && current->exp == exp) {
            current->coeff += coeff;
            free(newTerm);

            if (current->coeff == 0) {

                if (prev)
                    prev->next = current->next;
                else
                    *poly = current->next;
                free(current);
            }
        } else {
            newTerm->next = current;
            if (prev)
                prev->next = newTerm;
            else
                *poly = newTerm;
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
int first = 1; 

    while (poly != NULL) {
        if (poly->coeff != 0) {
            if (!first && poly->coeff > 0)
                printf(" + ");
            else if (poly->coeff < 0)
                printf(" - ");
            else if (!first) 
                printf(" ");

            int absCoeff = abs(poly->coeff);
            if (poly->exp == 0) {
                printf("%d", absCoeff);
            } else if (poly->exp == 1) {
                if (absCoeff != 1)
                    printf("%dx", absCoeff);
                else
                    printf("x");
 } else {
                if (absCoeff != 1)
                    printf("%dx^%d", absCoeff, poly->exp);
                else
                    printf("x^%d", poly->exp);
            }

            first = 0;
        }

        poly = poly->next;
    }

    printf("\n");
}
void subtract(char poly1, char poly2) {
    Term *p1 = NULL, *p2 = NULL;
    clearPolynomial(&R);

    switch (poly1) {
        case 'A': p1 = A; break;
        case 'B': p1 = B; break;
        case 'C': p1 = C; break;
    }
    switch (poly2) {
        case 'A': p2 = A; break;
        case 'B': p2 = B; break;
        case 'C': p2 = C; break;
    }

    while (p1) {
        insertTerm(&R, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2) {
        insertTerm(&R, -p2->coeff, p2->exp);
        p2 = p2->next;
    }
}

int main() {
    int termsA[][2] = {{2, 1}, {1, 0}};
    int termsB[][2] = {{1, 1}, {2, 0}};
    setPolynomial('A', termsA, 2);
    setPolynomial('B', termsB, 2);
    subtract('A', 'B');
    printPolynomial(R); 
    return 0;
}

