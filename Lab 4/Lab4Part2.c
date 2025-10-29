#include <stdio.h>
/**
 * Author: Pratham Lonial
 * Username: plonial
 * ID: 1369004
 */

int main(void){
    /**
     * Variable Decleration
     * integer num stores the value of the inputted integer that has to be reversed
     * integer reversedNum array is an array that stores a maximum value of 5 bits (since max = 10000) and is used to reverse the number
     * integer i is the starting point of the array to store the digits of integer num
     * integer originalNum stores the original inputted value of num to be displayed in the final output
     */
    int num;
    int reverseNum[5];
    int i = 0;
    int originalNum;

    do{
        printf("Enter a number(less than 10000): ");
        scanf("%d", &num);
        if(num < 0 || num > 10000){
            printf("Number must be between 0 and 10000. Please try again.");
        }
    } while(num < 0 || num > 10000);

    // num is stored as another variable to be outputted at the end
    originalNum = num;

    // if number is 0, it doesn't erase the 0 and just reprints it
    if(num == 0){
        printf("Original Number = 0"
               "Reversed Number = 0");
    }
    // if number is not 0
    else{
        // each digit of num is stored into the array from last to first
        while(num > 0){
            reverseNum[i++] = num % 10;
            num /= 10;
        }
        printf("Original Number = %d \n", originalNum);
        printf("Reversed Number = ");

        /**
         * Checks for leading 0s
         * integer start checks if the first digit of the array (last digit of num) is 0, if it is then it moves onto the next number
         */
        int start = 0;
        while(start < i && reverseNum[start] == 0){
            start++;
        }
        // prints the number from the point where there are no leading 0s left (integer start)
        for(int j = start; j < i; j++){
        printf("%d", reverseNum[j]);
        }
    }
    return 0;
}