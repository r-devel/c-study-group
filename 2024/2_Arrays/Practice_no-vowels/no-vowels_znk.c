// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels text");
        return 1;
    }

    string new = replace(argv[1]);

    printf("%s\n", new);

    return 0;
}

string replace(string word)
{
    int n = strlen(word);
    string new = word;
    for (int i = 0; i < n; i++)
    {
        switch(toupper(word[i]))
        {
            case 'A':
                new[i] = '6';
                break;
            case 'E':
                new[i] = '3';
                break;
            case 'I':
                new[i] = '1';
                break;
            case 'O':
                new[i] = '0';
                break;
            default:
                new[i] = word[i];
        }
    }
    return new;
}
