#include <stdio.h>

#define isdigit(a) (a >= '0' && a <= '9')

int getdigit(char *msg)
{
  printf("%s\n", msg);
  char c = getchar();
  while (!isdigit(c))
    c = getchar();
  return c - '0';
}

/*
 * if a is bigger than b, (a > b) condition will return 1, and 1 * a is a
 * and other condition statement will be 0, and 0 * b is 0
 * so sum of a + 0 or 0 + b equals to just 'a' or 'b'
 */
int max(int a, int b)
{
  return (a > b) * a + (b > a) * b;
}

/*
 * like max, but conditions are reversed to find min
 */
int min(int a, int b)
{
  return (a < b) * a + (b < a) * b;
}

int main()
{
  int a = 0, b = 0;
  a = getdigit("Enter A : ");
  b = getdigit("Enter B : ");
  printf("Max : %d \t Min : %d\n", max(a, b), min(a, b));
  return 0;
}
