#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float l = ((float) letters / (float) words) * 100.0;
    float s = ((float) sentences / (float) words) * 100.0;
    float index = (0.0588 * l) - (0.296 * s) - 15.8;
    int grade = round(index);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade == 1)
    {
        printf("Grade 1\n");
    }
    else if (grade == 2)
    {
        printf("Grade 2\n");
    }
    else if (grade == 3)
    {
        printf("Grade 3\n");
    }
    else if (grade == 4)
    {
        printf("Grade 4\n");
    }
    else if (grade == 5)
    {
        printf("Grade 5\n");
    }
    else if (grade == 6)
    {
        printf("Grade 6\n");
    }
    else if (grade == 7)
    {
        printf("Grade 7\n");
    }
    else if (grade == 8)
    {
        printf("Grade 8\n");
    }
    else if (grade == 9)
    {
        printf("Grade 9\n");
    }
    else if (grade == 10)
    {
        printf("Grade 10\n");
    }
    else if (grade == 11)
    {
        printf("Grade 11\n");
    }
    else if (grade == 12)
    {
        printf("Grade 12\n");
    }
    else if (grade == 13)
    {
        printf("Grade 13\n");
    }
    else if (grade == 14)
    {
        printf("Grade 14\n");
    }
    else if (grade == 15)
    {
        printf("Grade 15\n");
    }
    else if (grade == 16)
    {
        printf("Grade 16\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        int n = isalpha(text[i]);
        if (n != 0)
        {
            letters += 1;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] == ' ')
        {
            words += 1;
        }
    }
    return words + 1;
}

int count_sentences(string text)
{
    int sentences = 0;
    char marks[7] = {'.', '!', '?'};
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (text[i] == marks[j])
            {
                sentences += 1;
            }
        }
    }
    return sentences;
}
