#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string str);

int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("ERROR: Usage %s <word to be coverted>\n", argv[0]);
        return 1;
    }
    printf("%s\n", replace(argv[1]));
    return 0; // success
}

string replace(string str)
{
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        switch (str[i])
        {
            case 'a':
                str[i] = '6';
                break;
            case 'e':
                str[i] = '3';
                break;
            case 'i':
                str[i] = '1';
                break;
            case 'o':
                str[i] = '0';
                break;
            default:
                break;
        }
    }
    return str;
}
