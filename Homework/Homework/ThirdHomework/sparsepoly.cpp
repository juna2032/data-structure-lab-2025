#include "sparsepoly.hpp"

SparsePoly::SparsePoly() {
    numTerms = 0;
}

void SparsePoly::read() {
    printf("항의 개수를 입력하세요: ");
    scanf_s("%d", &numTerms);
    for (int i = 0; i < numTerms; i++) {
        float coef;
        int exp;
        printf("%d번째 항의 계수와 차수를 입력하세요 (예: 계수 차수): ", i + 1);
        scanf_s("%f %d", &coef, &exp);
        coefficients.push_back(coef);
        exponents.push_back(exp);
    }
}

void SparsePoly::display(const char* str) {
    printf("%s", str);
    for (int i = 0; i < numTerms; i++) {
        printf("%.1fx^%d", coefficients[i], exponents[i]);
        if (i != numTerms - 1) printf(" + ");
    }
    printf("\n");
}

void SparsePoly::add(SparsePoly a, SparsePoly b) {
    int i = 0, j = 0;
    while (i < a.numTerms && j < b.numTerms) {
        if (a.exponents[i] > b.exponents[j]) {
            exponents.push_back(a.exponents[i]);
            coefficients.push_back(a.coefficients[i]);
            i++;
        }
        else if (a.exponents[i] < b.exponents[j]) {
            exponents.push_back(b.exponents[j]);
            coefficients.push_back(b.coefficients[j]);
            j++;
        }
        else {
            float sum = a.coefficients[i] + b.coefficients[j];
            if (sum != 0) {
                exponents.push_back(a.exponents[i]);
                coefficients.push_back(sum);
            }
            i++; j++;
        }
    }
    while (i < a.numTerms) {
        exponents.push_back(a.exponents[i]);
        coefficients.push_back(a.coefficients[i]);
        i++;
    }
    while (j < b.numTerms) {
        exponents.push_back(b.exponents[j]);
        coefficients.push_back(b.coefficients[j]);
        j++;
    }
    numTerms = (int)exponents.size();
}