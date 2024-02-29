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
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol!\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool lower_case = false;
    bool upper_case = false;
    bool number = false;
    bool symbol = false;
    
    bool res = false;
    
    int n = strlen(password);
    for (int i = 0; i < n; i++)
    {
        // lowercase letters 97-122
        // uppercase letters 65-90
        // number 48-57
        // symbol 33-47,58-64, 91-96, 123-126 (space = 32; del = 127)
        // post edit: easier to use utilities, e.g. ispunct()!
        if (password[i] > 32 && password[i] < 127)
        {
            if (password[i] >= 97 && password[i] <= 122)
            {
                if (lower_case) // if found before, res will not change, so continue
                    continue;
                lower_case = true;
            }
            else if (password[i] >= 65 && password[i] <= 90)
            {
                if (upper_case)
                    continue;
                upper_case = true;
            }
            else if (password[i] >= 48 && password[i] <= 57)
            {
                if (number)
                    continue;
                number = true;
            }
            else
            {
                symbol = true;
            }
        }
    }
    res = lower_case && upper_case && number && symbol;
    if (res)
        break;
    i++;
}
return res;
}
