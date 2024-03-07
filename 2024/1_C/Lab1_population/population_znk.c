#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int llamas = 0;
    int end = 0;
    do
    {
        llamas = get_int("How many llamas you got? ");
    }
    while (llamas < 9);
    do
    {
        end = get_int("How many llamas you want? ");
    }
    while (end < llamas);

    int years = 0;
    int bebby; // births
    int meat;  // deaths
    while (llamas < end)
    {
        years++;
        bebby = llamas / 3;
        meat = llamas / 4;
        llamas -= meat;
        llamas += bebby;
    }
    printf("Years: %i\n", years);
}
