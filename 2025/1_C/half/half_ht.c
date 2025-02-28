#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // 1 not prime
    if (number == 1)
        return (false);
    for (int i = 2; i < number; i++)
    {
        int residual = number % i;
        // if number divisible by i, number is not prime
        if (!residual)
            return (false);
    }
    // if number is not divisible by any integer from 2 to number - 1, it must be prime
    return (true);
}
