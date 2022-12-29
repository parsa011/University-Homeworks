#include <iostream>
#include <string.h>

using namespace std;

void sort(string names[], int count)
{
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - i - 1; j++) {
      // if we want to sort them by length , we just have to check their length
      if (names[j].compare(names[j + 1]) > 0) {
	names[j].swap(names[j + 1]);
      }
    }
  }
}

int main()
{
  int count = 3;
  string names[count], temp;
  cout << "Enter " << count << " name\n";
  for (int i = 0; i < count; i++) {
    cout << i + 1 << " : ";
    cin >> temp;
    names[i] = temp;
  }

  sort(names, count);

  cout << "Sorted Names : \n";
  
  for (int i = 0; i < count; i++) {
    cout << names[i] << endl;
  }
  return 0;
}
