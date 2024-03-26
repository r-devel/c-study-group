// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    } 
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

int max(int array[], int n)
{
  int max = array[n - 1];
  while(n - 1 > 0) {
    if (array[n - 2] > max) max = array[n - 2];
    n--;
  }
  return max;
}
