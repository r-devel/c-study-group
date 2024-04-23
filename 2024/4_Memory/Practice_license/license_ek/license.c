#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers
    // N.B., this doesn't allocate memory for each of these pointers to hold a string
    // so need to do that later (in the loop)
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        /*
        Below is the original buggy line.
        It doesn't work because `buffer` is a pointer (arrays are pointers!)
        So each element of plates is getting updated with the same address,
        i.e. the value of `buffer`.
        Even though the string in `buffer` updates at each iteration, the value of buffer itself does not.
        After all the iterations, this address contains the last plate in the plates.txt,
        so all elements of the `plates` array print, as strings, the string in `buffer` at that point.
        A
        */
        // Save plate number in array
        // plates[idx] = buffer;

        /*
        instead, let's copy the plate, using `strcpy`, which has prototype
        `char *strcpy(char *dest, char *src);`
        We know the src, i.e. buffer
        Need a destination
        Using `plates[idx]` creates a segmentation fault, since it contains a garbage value.
        Need to malloc space first.
        Need to do this inside the loop, otherwise run into same issue as will original buggy line of code.
        */

        // allocate enough memory to hold the string in buffer (including the null terminator)
        plates[idx] = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(plates[idx], buffer);

        strcpy(plates[idx], buffer);
        idx++;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }

    // FREE MEMORY
    // close files
    fclose(infile);

    // free malloc'ed memory
    // can't do this until after plates have printed (i.e. not in while loop)
    // so we need another loop to make sure we free the memory for each element of plates
    for (int i = 0; i < idx; i++)
    {
        free(plates[i]);
    }
    // running valgrind confirms all memory now freed
}
