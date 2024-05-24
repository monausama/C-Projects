#include <cs50.h>
#include <stdio.h>
#define MAX 8

int digits(long num);
int first_digit(long num);

int main(void)
{
    long number = get_long("Number: ");
    int digits_num = digits(number);
    int first = first_digit(number);
    int arr1[MAX] = {0, 0, 0, 0, 0, 0, 0, 0};
    int i = 0;
    int r;
    long copy1 = number;
    while (copy1 != 0)
    {
        if (digits_num == 13 || digits_num == 15)
        {
            r = copy1 % 10;
            r *= 2;
            arr1[i] = r;
            i++;
            copy1 /= 100;
        }
        else if (digits_num == 16)
        {
            copy1 /= 10;
            r = copy1 % 10;
            r *= 2;
            arr1[i] = r;
            i++;
            copy1 /= 10;
        }
    }
    int sum1 = 0;
    for (i = 0; i < MAX; i++)
    {
        int x;
        int y;
        int d = digits(arr1[i]);
        if (d == 2)
        {
            x = arr1[i] % 10;
            y = arr1[i] /= 10;
            sum1 = sum1 + x + y;
        }
        else
        {
            sum1 += arr1[i];
        }
    }
    long copy2 = number;
    int j = 0;
    int arr2[MAX] = {0, 0, 0, 0, 0, 0, 0, 0};
    while (copy2 != 0)
    {
        if (digits_num == 13 || digits_num == 15)
        {
            copy2 /= 10;
            r = copy2 % 10;
            arr2[j] = r;
            j++;
            copy2 /= 10;
        }
        else if (digits_num == 16)
        {
            r = copy2 % 10;
            arr2[j] = r;
            j++;
            copy2 /= 100;
        }
    }
    int sum2 = 0;
    for (j = 0; j < MAX; j++)
    {
        sum2 += arr2[j];
    }
    int sum = sum1 + sum2;
    int last = sum % 10;
    if (last == 0)
    {
        if (digits_num == 15 && first == 3)
        {
            printf("AMEX\n");
        }
        if (digits_num == 16 && first == 5)
        {
            printf("MASTERCARD\n");
        }
        if ((digits_num == 13 || digits_num == 16) && first == 4)
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int digits(long num)
{
    int digits = 0;
    while (num != 0)
    {
        num /= 10;
        digits += 1;
    }
    return digits;
}

int first_digit(long num)
{
    while (num > 10)
    {
        num /= 10;
    }
    return num;
}
