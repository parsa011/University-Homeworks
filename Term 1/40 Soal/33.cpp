#include "global.h"

float calculate_l(int x1, int y1, int x2, int y2)
{
  return sqrt((float)pow(x1 - x2, 2) + (float)pow(y1 - y2, 2));
}

int main()
{
  int x1, y1;
  int x2, y2;
  int x3, y3;
  float a, b, c;
  cout << "Enter x1 and y1 : \n";
  cin >> x1 >> y1;
  cout << "Enter x2 and y2 : \n";
  cin >> x2 >> y2;
  cout << "Enter x3 and y3 : \n";
  cin >> x3 >> y3;
  a = calculate_l(x1, y1, x2, y2);
  b = calculate_l(x1, y1, x3, y3);
  c = calculate_l(x2, y2, x3, y3);
  cout << a << '\t' << b << '\t' << c << endl;
  float P = (a + b + c) / 2.0f;
  float S = sqrt(P * (P - a) * (P - b) * (P - c));
  cout << "P : " << P << " and S : " << S << endl;
  return 0;
}
