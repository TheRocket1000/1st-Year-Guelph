/**
 * Author: Pratham Lonial
 * Username: plonial
 * ID: 1369004
 */

#include <stdio.h>

int main(void) {
    /**Variable decleration
     * integer num stores the decimal input of the number that needs to be converted
     * the integer array of binary stores the binary digits for the decimal and stores up to 32 bits
     * integer i is used as an index to store binary digits
     */
    int num;
    int binary[32];
    int i = 0;

    // the user is asked for the number that they need to convert to binary
    do {
        printf("Enter a decimal number under 16: ");
        scanf("%d", &num);
        if (num > 15) {
            printf("Number must not exceed 15. Please try again.\n");
        }
    } while (num > 15);
    // if the inputted number is 0, the calculation is skipped and the answer is returned
    if (num == 0) {
        printf("Binary: 0\n");
        return 0;
    }

    // while the number is above 0, it is divided by 2 and the remainder is stored in the array
    while (num > 0) {
        binary[i++] = num % 2;
        num /= 2;
    }

    // prints out the values stored in the array one by one to form binary number
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    return 0;
}