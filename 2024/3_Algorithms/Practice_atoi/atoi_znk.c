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
    if (input[0] == '\0')
    {
        return 0;
    }
    int n = strlen(input);
    // convert the final character to integer
    int last = (int) input[n - 1] - '0';

    // move the null terminator
    input[n - 1] = '\0';

    // multiply the input by ten to move last to the correct place.
    return (convert(input) * 10) + last;
}
