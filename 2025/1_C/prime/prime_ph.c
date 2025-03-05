#include <cs50.h>
#include <stdio.h>

bool prime(int number);
void sieve_of_sundaram(int limit, bool sieve[]);

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
    if (number < 2)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    int n = (number - 1) / 2;
    bool sieve[n + 1];

    for (int i = 0; i <= n; i++)
        sieve[i] = false;

    sieve_of_sundaram(number, sieve);

    return !sieve[n];
}

void sieve_of_sundaram(int limit, bool sieve[])
{
    int n = (limit - 1) / 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; (i + j + 2 * i * j) <= n; j++)
        {
            sieve[i + j + 2 * i * j] = true;
        }
    }
}
