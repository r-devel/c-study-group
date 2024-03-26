#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // handle base case
    if (strlen(input) == 0)
    {
        return 0;
    }
    // convert last char to int
    int n = strlen(input);
    int digit = input[n - 1] - '0';

    // remove last char
    input[n - 1] = '\0';

    // add then convert next digit
    digit = digit + 10 * convert(input);
    return digit;
}
