// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");
    
    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

float half(float bill, float tax, int tip)
{
    float amount = bill * (100 + tax) / 100;
    // use 100.0 to make 100 a float
    amount = (100 + tip) / 100.0 * amount; // works if have "amount * (100 + tip) / 100"
    return amount / 2;
}
