#include <stdio.h>
#include "ComplexNumber.h"

int main() {

    ComplexNumber* num0 = createComplexNumber(2, 3);
    ComplexNumber* num1 = createComplexNumber(4, 5);

    ComplexNumber* theSum = sum(num0, num1);
    printf("The result of the sum between num0 and num1 is:  %.f + %.f i\n", theSum->real, theSum->imaginary);

    ComplexNumber* theSubtraction = subtract(num0, num1);
    printf("The result of the subtraction between num0 and num1 is:  %.f + %.f i\n", theSubtraction->real, theSubtraction->imaginary);

    ComplexNumber* theProduct = product(num0, num1);
    printf("The result of the product between num0 and num1 is:  %.f + %.f i\n", theProduct->real, theProduct->imaginary);

    double abs0 = absoluteValue(num0);
    printf("The absolute value of num0 is: %.2f\n", abs0);

    double abs1 = absoluteValue(num1);
    printf("The absolute value of num1 is: %.2f\n", abs1);

    double isEqual = equals(num0, num1);
    if (isEqual) {
        printf("num0 and num1 are equal\n");
    } else {
        printf("num0 and num1 are different\n");
    }

    destroyComplexNumber(num0);
    printf("num0 has been destroyed\n");

    destroyComplexNumber(num1);
    printf("num1 has been destroyed\n");


    return 0;
}
