#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ERROR_MESSAGE "Your password needs at least one uppercase letter, lowercase letter, number and symbol!"
#define VALID_MESSAGE "Your password is valid!"

int check_password(string pwd);
int main(int argc, string argv[])
{
    if (argc > 1)
    {
        printf("ERROR: Usage %s\n", argv[0]);
        return 1;
    }

    string password;
    do
    {
        password = get_string("Enter your password: ");
    }
    while (strlen(password) == 0);

    bool res = check_password(password);
    if (!res)
    {
        printf("%s\n", ERROR_MESSAGE);
        return 1;
    }
    printf("%s\n", VALID_MESSAGE);
    return 0; // success
}

int check_password(string pwd)
{
    bool has_capital = false;
    bool has_symbol = false;
    bool has_digit = false;
    bool has_lower = false;

    for (int i = 0, n = strlen(pwd); i < n; i++)
    {
        if (isdigit(pwd[i]))
        {
            has_digit = true;
        }
        else if (ispunct(pwd[i]))
        {
            has_symbol = true;
        }
        else if (isupper(pwd[i]))
        {
            has_capital = true;
        }
        else if (islower(pwd[i]))
        {
            has_lower = true;
        }

        if (has_capital && has_digit && has_symbol && has_lower)
            return true;
    }

    return false;
}
