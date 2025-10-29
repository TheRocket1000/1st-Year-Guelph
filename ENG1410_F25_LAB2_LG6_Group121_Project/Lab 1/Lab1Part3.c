/**
 * Author: Pratham Lonial
 * Username: plonial
 * ID: 1369004
 */

#include <stdio.h>

int main(void){
const double KgPerPound = 2.20;
const double OuncesPerPound = 16.0;
double weight;

printf("Please enter a weight in kilograms: ");
scanf("%lf", &weight);

//Convert kilograms to pounds
double weightInPounds = weight * KgPerPound;

//Convert pounds to ounces
double totalOunces = weightInPounds * OuncesPerPound;

printf("%.2lf kilograms, %.2lf pounds, %.2lf ounces\n", weight, weightInPounds, totalOunces);
return 0;
}
