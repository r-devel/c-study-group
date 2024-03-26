#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

/*
  Calculate either the total hours worked over a user given number of hours per week or
  the average hour per week over those weeks
*/

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

float calc_hours(int hours[], int weeks, char output)
{
    float sum = 0.0;
    for (int i = 0; i < weeks; i++)
    {
        sum += (float) hours[i];
    }    
    return (output == 'T') ? sum : sum / (float) weeks;
}
