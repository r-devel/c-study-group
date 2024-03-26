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
    int length = strlen(input);

    // Base case
    if (length == 1)
        return input[0] - '0';

    // Get last digit and convert to int
    int last_digit_index = length - 1;
    int last_digit = input[last_digit_index] - '0';

    // Remove the last char from the string
    // by moving the null terminator one position to the left
    input[last_digit_index] = '\0';

    // Return last_digit plus 10 times the integer value of the new shortened string
    return last_digit + 10 * convert(input);
}
