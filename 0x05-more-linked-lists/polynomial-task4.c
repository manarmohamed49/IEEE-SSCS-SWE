#include <stdio.h>
#include <math.h>


void evaluatePolynomial(char poly, float x) {
    Term *head = getPolynomial(poly);
    float result = 0.0;

    while (head != NULL) {
        result += head->coeff * pow(x, head->exp);
        head = head->next;
    }

    printf("Result = %.1f\n", result);
}
int main() {
    int termsA[][2] = {{3,2},{2,1},{1,0}};
    setPolynomial('A', termsA, 3);
    evaluatePolynomial('A', 2.0);
    return 0;
}

