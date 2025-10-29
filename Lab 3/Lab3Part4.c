/**
 * Author: Pratham Lonial
 * Username: plonial
 * ID: 1369004
 */

#include <stdio.h>

int main(void){

    /**Variable decleration
     * integer num stores the value of the inputted number that needs to be added
     */
    int num;
    int sum = 0 ;

    do {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num < 0 || num > 99999) {
            printf("Number must be between 0 and 99999. Please try again.\n");
        }
    } while (num < 0 || num > 99999);

    // divided by 10 to isolate for the last digit and find remainder
    // divided by 10 and kept as integer so last digit is removed
    while (num != 0){
        sum += num % 10;
        num /= 10;
    }

    printf("Sum of digits: %d\n", sum);
    return 0;
}