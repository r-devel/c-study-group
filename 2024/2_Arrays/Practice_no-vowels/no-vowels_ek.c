// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    // Check just one command line arg
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    // replace vowels with numbers
    string new = replace(argv[1]);

    // print new word
    printf("%s\n", new);
}

/* N.B. main takes `string argv[]` as an argument
since there can be more than command line argument.
For a function that takes a single sting,
we just need `string arg_name` (no [])
*/
string replace(string word)
{

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        switch (word[i])
        {
            case 'a':
                word[i] = '6';
                break;

            case 'e':
                word[i] = '3';
                break;

            case 'i':
                word[i] = '1';
                break;

            case 'o':
                word[i] = '0';
                break;
        }
    }
    return word;
}
