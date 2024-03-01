// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>


string replace(string word); 

int main(int argc, string argv[])
{
  if (argc != 2) {
    printf("Provide exactly one word as argument.\n");
    return 1;
  }

  printf("%s\n", replace(argv[1]));
  printf("%s\n", argv[1]); // To demonstrate that argument to the function was also changed because we pass pointer to char.
  return 0;
}

string replace(string word) {
  int i = 0;
  while(word[i]) {
    switch(word[i]) {
      case 'a':
        word[i] = '6';
        break;
      case 'e':
        word[i] = '3';
        break;
      case 'i':
        word[i] = '1';
        break;
      case 'o':
        word[i] = '0';
        break;
    }
    i++;
  }
  return word;
}
