/*
    Description: Header file that describes the ComplexNumber ADT.
 */

#ifndef COMPLEXNUMBER_COMPLEXNUMBER_H
#define COMPLEXNUMBER_COMPLEXNUMBER_H

//Structs

struct ComplexNumber{
    double real;
    double imaginary;
}typedef ComplexNumber;

//Function

ComplexNumber* createComplexNumber(double aReal, double aImaginary);
ComplexNumber* sum(ComplexNumber* c1, ComplexNumber* c2);
ComplexNumber* subtract(ComplexNumber* c1, ComplexNumber* c2);
ComplexNumber* product(ComplexNumber* c1, ComplexNumber* c2);
double absoluteValue(ComplexNumber* c1);
double equals(ComplexNumber* c1, ComplexNumber* c2);
void destroyComplexNumber(ComplexNumber* c);

#endif //COMPLEXNUMBER_COMPLEXNUMBER_H
