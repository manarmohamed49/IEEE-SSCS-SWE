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

void add(char poly1, char poly2) {
    Term *p1 = NULL, *p2 = NULL;
    switch (poly1) {
        case 'A': p1 = A; break;
        case 'B': p1 = B; break;
        case 'C': p1 = C; break;
        case 'R': p1 = R; break;
        default:
            printf("Unknown polynomial %c\n", poly1);
            return;
    }

    switch (poly2) {
        case 'A': p2 = A; break;
        case 'B': p2 = B; break;
        case 'C': p2 = C; break;
        case 'R': p2 = R; break;
        default:
            printf("Unknown polynomial %c\n", poly2);
            return;
    }


    clearPolynomial(&R);

    while (p1 && p2) {
        if (p1->exp > p2->exp) {
            insertTerm(&R, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insertTerm(&R, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                insertTerm(&R, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    
    while (p1) {
        insertTerm(&R, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2) {
        insertTerm(&R, p2->coeff, p2->exp);
        p2 = p2->next;
    }
}
int main() {
    int termsA[][2] = {{2,1},{3,0}};
    int termsB[][2] = {{1,1},{4,0}};
    setPolynomial('A', termsA, 2);
    setPolynomial('B', termsB, 2);

    add('A', 'B');

    printf("R = ");
    printPolynomial(R);
    return 0;
}
