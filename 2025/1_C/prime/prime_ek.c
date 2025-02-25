#include <cs50.h>
#include <stdio.h>
#include <math.h>

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
    if (number == 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        // if the number % i is 0 (i.e. false), the number is not prime
        // in this case, !(number % i) is true, so can return false
        if (!(number % i))
        {
            return false;
        }
    }

    return true;
}
