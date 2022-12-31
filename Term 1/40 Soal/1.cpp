#include <iostream>
#include <math.h>

using namespace std;

#define MAX 20

#define ISDIGIT(c) (c >= '0' && c <= '9')

#define POLY_MULTIPLY(a, a_len, b, b_len, op) { \
    int max = max(a_len, b_len);		\
    for (int i = 0; i < max; i++) {		\
      
    }						\
  }

/*
  a1 + a2 . x + ... + an + x^n
 */

int get_poly(int bag[])
{
  int len = 0;
  char ch = getchar();
  while (len + 1 < 20 && ch != '-' && ISDIGIT(ch)) {
    bag[len] = ch;
    ch = getchar();
    
  }
  return len;
}

void poly_multiply(int a, int a_len, int b, int b_len, int result[])
{
   int result[a + b];
   return result;
}

int main()
{
  int a[MAX], b[MAX];
  cout << "Enter First Poly : \n";
  int a_len = get_poly(a);
  cout << "Enter Second Poly : \n";
  int b_len = get_poly(b);
  char op = getchar();
  while (op != '+' || op != '/' || op != '*' || op != '-')
    op = getchar();
  POLY_MULTIPLY(a, a_len, b, b_len, op);
  return 0;
}
