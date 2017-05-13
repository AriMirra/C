/*
    Description: C file that contains the functions related to the ComplexNumber ADT.
    ComplexNumber manages all it's memory.
*/

#include "ComplexNumber.h"
#include <stdlib.h>
#include <math.h>

ComplexNumber* createComplexNumber(double real, double imaginary) {

    ComplexNumber *result = malloc(sizeof(ComplexNumber));

    result->real = real;
    result->imaginary = imaginary;

    return result;
}

ComplexNumber* sum(ComplexNumber* c1, ComplexNumber* c2) {
    double newReal = c1->real + c2->real;
    double newIm = c1->imaginary + c2->imaginary;
    ComplexNumber* num = createComplexNumber(newReal, newIm);
    return num;
}

ComplexNumber* subtract(ComplexNumber* c1, ComplexNumber* c2) {
    double newReal = c1->real - c2->real;
    double newIm = c1->imaginary - c2->imaginary;
    ComplexNumber* num = createComplexNumber(newReal, newIm);
    return num;
}

ComplexNumber* product(ComplexNumber* c1, ComplexNumber* c2) {
    double newReal = (c1->real * c2->real) - (c1->imaginary * c2->imaginary);
    double newIm = (c1->real * c2->imaginary) + (c1->imaginary * c2->real);
    ComplexNumber* num = createComplexNumber(newReal, newIm);
    return num;
}

double absoluteValue(ComplexNumber* c1) {
    double abs = sqrt((c1->real * c1->real) + (c1->imaginary * c1->imaginary));
    return abs;
}

double equals(ComplexNumber* c1, ComplexNumber* c2) {
    if ((c1->real == c2->real) && (c1->imaginary == c2->imaginary)) {
        return 1;
    }
    return 0;
}

void destroyComplexNumber(ComplexNumber* c) {
    free(c);
}
