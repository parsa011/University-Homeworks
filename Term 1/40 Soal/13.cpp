#include <iostream>
#include <fstream>

using namespace std;

const char *output_file = "class.bin";

int main()
{
  int n;
  cout << "Enter Students Count : ";
  cin >> n;
  string name, student_id;
  int score;
  ofstream file(output_file);
  for (int i = 0; i < n; i++) {
    file << to_string(i + 1) << " : ";
    
    cout << "Student[" << i + 1 << "] Score : ";
    cin >> score;
    file << to_string(score) << '\t';
    
    cout << "Student[" << i + 1 << "] Name : ";
    cin >> name;
    file << name << '\t';
    
    cout << "Student[" << i + 1 << "] Id : ";
    cin >> student_id;
    file << student_id << endl;
    
  }
  file.close();
  return 0;
}
