#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        int l = strlen(argv[1]);
        if (l != 26)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        for (int i = 0; i < l; i++)
        {
            int alpha = isalpha(argv[1][i]);
            if (alpha == 0)
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
            for (int m = i + 1; m < l; m++)
            {
                if (argv[1][i] == argv[1][m])
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
            }
        }
        string plain = get_string("plaintex:");
        int length = strlen(plain);
        string k = argv[1];
        printf("ciphertext:");
        for (int j = 0; j < length; j++)
        {
            int text = isalpha(plain[j]);
            if (text != 0)
            {
                int lower = islower(plain[j]);
                if (lower != 0)
                {
                    int il = plain[j] - 97;
                    printf("%c", tolower(argv[1][il]));
                }
                else
                {
                    int iu = plain[j] - 65;
                    printf("%c", toupper(argv[1][iu]));
                }
            }
            else
            {
                printf("%c", plain[j]);
            }
        }
    }
    printf("\n");
    return 0;
}
