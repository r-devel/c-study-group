/*

$ ./scrabble
Sample runs;
Player 1: Question?
Player 2: Question!
Tie!

$ ./scrabble
Player 1: red
Player 2: wheelbarrow
Player 2 wins!

$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!

$ ./scrabble
Player 1: Scrabble
Player 2: wiNNeR
Player 1 wins!

*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calc_score(string word, int scores[]);
string get_word(int player_no);

int main(int argc, string argv[])
{
    if (argc > 1)
    {
        printf("ERROR: Usage %s\n", argv[0]);
        return 1;
    }
    int scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    string words[2];
    for (int i = 0; i < 2; i++)
    {
        words[i] = get_word(i);
    }
    int totals[2];
    for (int i = 0; i < 2; i++)
    {
        totals[i] = calc_score(words[i], scores);
    }
    if (totals[0] > totals[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (totals[0] == totals[1])
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
    return 0; // success
}

string get_word(int player_no)
{
    string word;
    do
    {
        word = get_string("Player %i: ", player_no + 1);
    }
    while (strlen(word) == 0);
    return word;
}

int calc_score(string word, int scores[])
{
    int sum = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i]))
        {
            char c = toupper(word[i]);
            int idx = (int) (c - 'A');
            sum += scores[idx];
        }
    }
    return sum;
}
