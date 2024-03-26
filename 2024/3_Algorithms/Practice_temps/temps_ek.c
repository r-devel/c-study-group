// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void bubble_sort_cities(void);
void selection_sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    bubble_sort_cities();
    // selection_sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// This is algorithm from the short, not the lecture
void bubble_sort_cities(void)
{
    int swaps = -1;
    int iters = 0;
    avg_temp tmp;

    while (swaps != 0)
    {
        swaps = 0;

        /*
        NUM_CITIES - 1 - iters:
        - 1 is so don't index outside array when comparing adjacent pairs
        - iters because for each iteration of while loop, another element at the end of array guaranteed to be in place,
        so don't need to check it.
        N.B. iters counts number of iterations through the while loop, and is unrelated it i in the inner for loop.
        */
        for (int i = 0; i < NUM_CITIES - 1 - iters; i++)
        {
            // swap pairs if out of order,
            // moving smallest further along array
            if (temps[i].temp < temps[i + 1].temp)
            {
                // put current value at i + 1 into tmp
                tmp = temps[i + 1];

                // move values from i into i + 1
                temps[i + 1] = temps[i];

                // move values from tmp (previously i + 1) into i
                temps[i] = tmp;

                // increase swaps
                swaps++;
            }
        }

        // have been through a full inner loop,
        // so keep track of how many times we've been round the while loops
        iters++;
    }
}

void selection_sort_cities(void)
{
    for (int i = 0; i < NUM_CITIES; i++)
    {
        // Find largest number between temps[i] and temps[n - 1]
        // The first element, at i, is the first largest to compare against...
        avg_temp largest_temp = temps[i];
        int index_of_largest = i;

        //...then compare starting at (i + 1)
        for (int j = i + 1; j < NUM_CITIES; j++)
        {
            if (temps[j].temp > largest_temp.temp)
            {
                largest_temp = temps[j];
                index_of_largest = j;
            }
        }

        // swap, if necessary
        if (i != index_of_largest)
        {
            // move values from i into position of largest
            temps[index_of_largest] = temps[i];

            // move values of largest (already stored in a tmp) into i
            temps[i] = largest_temp;
        }
    }
}
