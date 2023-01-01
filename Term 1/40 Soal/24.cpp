#include "global.h"

int main()
{
  string f;
  cout << "Enter File Name : ";
  cin >> f;
  fstream file(f.c_str(), ios::out);
  int employees_count;
  cout << "Enter Employees Count : ";
  cin >> employees_count;

  /* ues, salary as string :)) */
  string name, job, salary;
  for (int i = 0; i < employees_count; i++) {
    file << to_string(i + 1) << " : ";
    
    cout << "Employee[" << i + 1 << "] Name : ";
    cin >> name;
    file << name << '\t';
    
    cout << "Employee[" << i + 1 << "] Job : ";
    cin >> job;
    file << job << '\t';
    
    cout << "Employee[" << i + 1 << "] Salary : ";
    cin >> salary;
    file << salary << endl;
  }
  file.close();

  return 0;
}
