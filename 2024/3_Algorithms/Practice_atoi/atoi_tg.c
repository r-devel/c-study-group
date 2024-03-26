#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);
int convert2(string input, int n);

int main(void)
{
    string input = get_string("Enter a positive integer: ");
    char input2[1000];

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }
    strcpy(input2, input);
    // Convert string to int
    printf("convert: %i\n", convert(input));
    printf("convert2: %i\n", convert2(input2, 0));
}

int convert(string input)
{
  int last_ind = strlen(input) - 1;
  int n = 0;
  if (last_ind >= 0) {
    n = input[last_ind] - '0';
    input[last_ind] = 0;
    n = n + 10 * convert(input);
  }
  return n;
}

int convert2(string input, int n) {
  if (*input != '\0') {
    n = 10 * n + (*input - '0');
  } else {
    return n;
  }
  return convert2(input + 1, n);
}
