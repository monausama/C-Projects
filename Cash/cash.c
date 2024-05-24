#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);
    int sum = 0;
    while (change >= 25)
    {
        sum += 1;
        change -= 25;
    }
    while (change >= 10)
    {
        sum += 1;
        change -= 10;
    }
    while (change >= 5)
    {
        sum += 1;
        change -= 5;
    }
    while (change >= 1)
    {
        sum += 1;
        change -= 1;
    }
    printf("%i\n", sum);
}
