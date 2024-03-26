// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// Complete the Boolean function below
// Simple but not as efficient as could be:
// iterates over whole password, even after it could already be declared valid
bool valid(string password)
{
    int upper = 0;
    int lower = 0;
    int number = 0;
    int symbol = 0;

    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (isupper(password[i]))
        {
            upper++;
        }
        else if (islower(password[i]))
        {
            lower++;
        }
        else if (isdigit(password[i]))
        {
            number++;
        }
        else if (ispunct(password[i]))
        {
            symbol++;
        }
    }

    // any number other than 0 evaluates to true
    return upper && lower && number && symbol
}
