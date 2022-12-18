#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
  int count, n;
  string s; 
  cout << "Enter Students Count : ";
  cin >> count;
  int scores[count];
  string names[count];
  for (int i = 0; i < count; i++) {
    cout << "Student[" << i + 1 << "] Score : ";
    cin >> n;
    cout << "Enter His Name : ";
    cin >> s;
    scores[i] = n;
    names[i] = s;
  }
  int bs_score = -1, bs_index = -1;
  int ws_score = 21, ws_index = -1;
  for (int i = 0; i < count; i++) {
    if (scores[i] > bs_score) {
      bs_index = i;
      bs_score = scores[i];
    }
    if (scores[i] < ws_score) {
      ws_index = i;
      ws_score = scores[i];
    }
  }
  cout << "Best Student Is : '" << names[bs_index] << "' With : " << scores[bs_index] << endl;
  cout << "Worse Student Is : '" << names[ws_index] << "' With : " << scores[ws_index] << endl;
  return 0;
}
