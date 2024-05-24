#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }
    else
    {
        for (int i = 0, l = strlen(argv[1]); i < l; i++)
        {
            int digit = isdigit(argv[1][i]);
            if (digit == 0)
            {
                printf("Usage: ./caeser key\n");
                return 1;
            }
        }
        int k = atoi(argv[1]);
        string plain = get_string("plaintext:  ");
        int length = strlen(plain);
        printf("ciphertext: ");
        for (int j = 0; j < length; j++)
        {
            int alpha = isalpha(plain[j]);
            if (alpha != 0)
            {
                int lower = islower(plain[j]);
                int plindex[length];
                int clindex[length];
                int puindex[length];
                int cuindex[length];
                if (lower != 0)
                {
                    plindex[j] = plain[j] - 97;
                    clindex[j] = (plindex[j] + k) % 26;
                    clindex[j] += 97;
                    printf("%c", clindex[j]);
                }
                else
                {
                    puindex[j] = plain[j] - 65;
                    cuindex[j] = (puindex[j] + k) % 26;
                    cuindex[j] += 65;
                    printf("%c", cuindex[j]);
                }
            }
            else
            {
                printf("%c", plain[j]);
            }
        }
        printf("\n");
        return 0;
    }
}
