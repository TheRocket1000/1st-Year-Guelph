/**
 * Author: Pratham Lonial
 * Username: plonial
 * ID: 1369004
 */

#include <stdio.h>

int main(void){
    //Variable decleration
    float billAmount;
    int tipPercentage;
    int numPeople;

    printf("Enter the original bill amount: ");
    scanf("%f", &billAmount);
    printf("Enter the tip percentage: ");
    scanf("%d", &tipPercentage);
    printf("Enter the number of people splitting the bill: ");
    scanf("%d", &numPeople);
    
    float tipAmount = (billAmount * tipPercentage) / 100;
    float totalBill = billAmount + tipAmount;
    float amountPerPerson = totalBill / numPeople;

    printf("The total bill amount is: $%.2f\n", totalBill);
    printf("Each person should pay: $%.2f\n", amountPerPerson);

    return 0;
}