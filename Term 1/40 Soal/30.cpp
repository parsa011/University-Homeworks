#include "global.h"

int main()
{
  int m, n;
  cout << "Enter m and n (size : m * n) : \n";
  cin >> m >> n;
  int matrix[m][n], matrix_t[n][m];
  int i, j;
  int num;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      cout << "matrix[" << i << "][" << j << "] : ";
      cin >> num;
      matrix[i][j] = num;
    }
    cout << endl;
  }
  
  // calculating t matrix
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      matrix_t[j][i] = matrix[i][j];
    }
    cout << endl;
  }

  // showing result
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << matrix_t[i][j] << '\t';
    }
    cout << endl;
  
}
  return 0;
}
