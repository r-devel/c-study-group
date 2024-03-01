// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);
int isnotalnum(int);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

bool valid(string password)
{
  bool valid = false;
  typedef int (*is_func_t) (int);
  is_func_t funcs[] = {&isnotalnum, &islower, &isupper, &isdigit};
  int FUNC_LEN = 4;
  for (int f = 0, i = 0; f < FUNC_LEN; f++, i = 0) {
    printf("f:%i\n", f);
    while(password[i]) {
      printf("%i:%c\n", i, password[i]);
      if (funcs[f](password[i])) {
        valid = true;
        printf("valid!\n\n");
        break;
      }
      i++;
    }
    if (password[i] == '\0') {
      valid = false;
      printf("end of string\n");
      break;
    }
  }
  return valid;
}

int isnotalnum(int c) {
  return !isalnum(c);
}
