#include <iostream>

using namespace std;

int centigrade_to_fahrenheit(int t)
{
  return (t * 9 / 5) + 32;
}

int centigrade_to_kelvin(int n)
{
  return n + 273;
}

int main()
{
  int temperature = 0;
  cout << "Enter Tempreture by Centigrade : ";
  cin >> temperature;
  cout << "By Fahrenheit : " << centigrade_to_fahrenheit(temperature) << "\t And kelvin : " << centigrade_to_kelvin(temperature) << endl;
  return 0;
}
