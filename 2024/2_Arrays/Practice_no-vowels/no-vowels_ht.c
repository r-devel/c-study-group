// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h> // toupper
#include <stdio.h>
#include <string.h> //strlen

string replace(string word);

int main(int argc, string argv[])
{
    // must accept word as single command line argument
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    string val = replace(argv[1]);
    printf("%s\n", val);
}

string replace(string word)
{
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // post edit: neater to use char directly here instead of converting to int!
        switch (toupper(word[i]) - 65)
        {
        case 0:
            word[i] = '6'; // A
            break;
        case 4:
            word[i] = '3'; // E
            break;
        case 8:
            word[i] = '1'; // I
            break;
        case 14:
            word[i] = '0'; // O
            break;
        }
    }
    return word;
}
