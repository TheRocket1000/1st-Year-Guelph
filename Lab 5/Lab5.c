#include <stdio.h>

/**
 * Author: Pratham Lonial
 * Username: plonial
 * ID: 1369004
 */

int baseConversion(int num, int base){
    if (base < 2 || base > 10 || num < 0){ 
        return -1;
    }
    int result = 0;
    int power = 1;
    while (num > 0) {
        int digit = num % 10;
        if (digit >= base){
        // Invalid digit for the given base
            return -1;
        }
        result += digit * power;
        power *= base;
        num /= 10;
    }
    return result;
}

int main(void){
    /**
     * Variable Decleration
     * char op stores the character of the operation that will occur
     * base_1 is the input base
     * base_2 is the output base
     * value_1 is the 1st value that the operation will happen on
     * value_2 is the 2nd value that the operation will happen on
     */

    char op;
    int base_1;
    int base_2;
    int value_1;
    int value_2;

    while(1){
        // Taking input from the user (moved inside the loop to read repeatedly)
        printf("Give input ($ to stop): ");
        int num_parsed = scanf("%c %d %d %d %d", &op, &base_1, &value_1, &value_2, &base_2);

        if(num_parsed == 1 && op == '$'){
            break;
        }
    // Validating Input
        else if (num_parsed != 5) {
            printf("Invalid input format\n");
            continue;
        }
    // Validating Operator and Bases
        else if (op != '+' && op != '-' && op != '*' && op != '/' && op != '$') {
            printf("Invalid operator\n");
            continue;
        }
        else if (base_1 < 2 || base_1 > 10 || base_2 < 2 || base_2 > 10) {
            printf("Invalid base\n");
            continue;
        }
        int converted_1 = baseConversion(value_1, base_1);
        int converted_2 = baseConversion(value_2, base_1);
        if (converted_1 == -1 || converted_2 == -1) {
            printf("Invalid number for the given base\n");
            continue;
        }
        int num1 = converted_1;
        int num2 = converted_2;
        int result;
        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error: Division by zero\n");
                    continue;  // Added continue to skip printing on error
                }
                result = num1 / num2;
                break;
            default:
                printf("Invalid operator\n");
                continue;  // Added continue
        }
        // Convert result to output base (using the existing function, even if flawed)
        int final_result = baseConversion(result, base_2);
        
        // Print the statement (moved inside the loop to print for each valid input)
        printf("%d %c %d (base %d) = %d %c %d = %d (base %d)\n", value_1, op, value_2, base_1, num1, op, num2, final_result, base_2);
    }
    
    return 0;
}
