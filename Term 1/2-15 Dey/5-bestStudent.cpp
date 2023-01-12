#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  int n, a;
  cout << "Enter Students Count : ";
  cin >> n;
  cout << endl;
  
  int scores[n];
  string names[n], ids[n], temp_s;

  int i, j;
  
  for (i = 0; i < n; i++) {
    cout << "Student[" << i + 1 << "] Score : ";
    cin >> a;
    scores[i] = a;

    cout << "Student[" << i + 1 << "] Name : ";
    cin >> temp_s;
    names[i] = temp_s;
    
    cout << "Student[" << i + 1 << "] Id : ";
    cin >> temp_s;
    ids[i] = temp_s;

    cout << endl;
  }

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (scores[j] < scores[j + 1]) {
        int temp = scores[j];
        scores[j] = scores[j + 1];
        scores[j + 1] = temp;

        names[j].swap(names[j + 1]);

        ids[j].swap(ids[j + 1]);
      }
    }
  }
  
  cout << "Best Students : \n\n";

  for (i = 0; i < 3; i++) {
    cout << names[i] << "(" << ids[i] << ") : " << scores[i] << endl;
  }

  return 0;
}
