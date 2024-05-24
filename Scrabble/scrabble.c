#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score(string player);

int main(void)
{
    // Taking the two player words
    string player1 = get_string("Player1: ");
    string player2 = get_string("Player2: ");
    // Calculating player1 word points
    int score1 = score(player1);
    int score2 = score(player2);
    // Print out the result
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int score(string player)
{
    int score = 0;
    for (int n = 0, l = strlen(player); n < l; n++)
    {
        player[n] = toupper(player[n]);
    }
    char point1[10] = {'A', 'E', 'I', 'L', 'N', 'O', 'R', 'S', 'T', 'U'};
    char point2[2] = {'D', 'G'};
    char point3[4] = {'B', 'C', 'M', 'P'};
    char point4[5] = {'F', 'H', 'V', 'W', 'Y'};
    char point5[1] = {'K'};
    char point8[2] = {'J', 'X'};
    char point10[2] = {'Q', 'Z'};
    for (int i = 0; i < strlen(player); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (player[i] == point1[j])
            {
                score += 1;
            }
        }
        for (int k = 0; k < 2; k++)
        {
            if (player[i] == point2[k])
            {
                score += 2;
            }
            if (player[i] == point8[k])
            {
                score += 8;
            }
            if (player[i] == point10[k])
            {
                score += 10;
            }
        }
        for (int x = 0; x < 4; x++)
        {
            if (player[i] == point3[x])
            {
                score += 3;
            }
        }
        for (int y = 0; y < 5; y++)
        {
            if (player[i] == point4[y])
            {
                score += 4;
            }
        }
        if (player[i] == point5[0])
        {
            score += 5;
        }
    }
    return score;
}
