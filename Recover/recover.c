#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Can't open the file!");
        return 1;
    }
    BYTE buffer[512];
    int n = 0;
    char file_name[8];
    sprintf(file_name, "%03i.jpg", n);
    FILE *img = NULL;
    while (fread(&buffer, 1, 512, card) == 512)
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) &&
            ((buffer[3] & 0xf0) == 0xe0))
        {
            if (n == 0)
            {
                sprintf(file_name, "%03i.jpg", n);
                img = fopen(file_name, "w");
                n++;
            }
            else
            {
                fclose(img);
                sprintf(file_name, "%03i.jpg", n);
                img = fopen(file_name, "w");
                n++;
            }
            fwrite(&buffer, 1, 512, img);
        }
        else
        {
            if (n != 0)
            {
                fwrite(&buffer, 1, 512, img);
            }
        }
    }
    fclose(img);
    fclose(card);
    return 0;
}
