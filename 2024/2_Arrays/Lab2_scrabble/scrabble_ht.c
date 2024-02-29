#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    
    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    
    // Print the winner
    if (score1 == score2)
        printf("Tie!\n");
    else
        printf("Player %i wins!\n", 1 + (score2 > score1));
}

int compute_score(string word)
{
    // Compute and return score for string
    //  - only compute strlen once
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // convert char to index from 0 (A = 65 in ASCII)
        int ind = toupper(word[i]) - 65;
        if (ind >= 0 && ind <= 25)
            score += POINTS[ind];
    }
    return score;
}
