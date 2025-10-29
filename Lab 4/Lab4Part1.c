#include <stdio.h>
/**
 * Author: Pratham Lonial
 * Username: plonial
 * ID: 1369004
 */

int main(void){
    /**
     * Variable Decleration
     * integer num stores the value of the inputted integer that is used for precision of pi
     */
    int num;
    do{
        printf("Enter the number of terms to approximate pi: ");
        scanf("%d", &num);
        if(num < 1){
            printf("Number must be positive. Please try again.\n");
        }
    } while(num < 1);

    /**
     * Calculating pi using the series
     * double sum stores the sum of the series
     * double denominator stores the denominator of each term in the series
     * double sign stores whether the term is positive or negative
     */
    double sum = 0;
    for(int i = 1; i <= num; i++){
        // denominator always needs to be odd so the formula 2n-1 is used
        double denominator = 2 * i - 1;
        double sign;
        // if i is even, the term is negative, if i is odd, the term is positive
        if(i % 2 == 0){
            sign = -1;
        } else{
            sign = 1;
        }
        // each term is added to the sum
        sum += sign / denominator;
    }
    // pi is 4 times the sum of the series
    double pi = 4 * sum;

    printf("Estimated value of (pi) after %d terms: %.3f\n", num, pi);
    return 0;
}