// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
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

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool upper = false;
    bool lower = false;
    bool numbr = false;
    bool symbl = false;
    bool valid = false;
    int n = strlen(password);
    for (int i = 0; i < n; i++)
    {
        char ltr = password[i];
        if ((!upper || !lower) && isalpha(ltr))
        {
            if (isupper(ltr))
            {
                upper = true;
            }
            else
            {
                lower = true;
            }
        } else if (!numbr && isdigit(ltr)) {
            numbr = true;
        } else if (!symbl && ispunct(ltr))
        {
            symbl = true;
        }
        else
        {
            // nothing to do
        }

        valid = upper && lower && numbr && symbl;
        if (valid)
        {
            return true;
        }
    }
    return false;
}
