#include "global.h"

void cal_det(void *arr, int n, int pos, int &det, int sign)
{
  int (*matrix)[n][n] = (int (*)[n][n]) arr;
  
  if (pos >= n)
    return;
  if (n == 2) {
    det = (*matrix)[0][0] * (*matrix)[1][1] - (*matrix)[0][1] * (*matrix)[1][0];
    // cout << det << endl;
    return;
  }

  // temp matrix or sub matrix
  int tm[n - 1][n - 1];
  int tm_i = 0, tm_j = 0;
  for (int i = 1; i < n; i++) {
    tm_j = 0;
    for (int k = 0; k < n; k++) {
      if (pos == k)
	continue;
      tm[tm_i][tm_j++] = (*matrix)[i][k];
    }
    tm_i++;
  }

  // for (int i = 0; i < n - 1; i++) {
  //   for (int k = 0; k < n - 1; k++) {
  //     cout << tm[i][k] << '\t';
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  
  int sub_det = 0;
  cal_det(tm, n - 1, 0, sub_det, 1);
  det += sign * (*matrix)[0][pos] * (sub_det);
  cal_det(arr, n, ++pos, det, sign * -1);
}

int main()
{
  int det = 0;
  int n;
  cout << "Enter matrix size : ";
  cin >> n;
  int matrix[n][n];

  int t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << "matrix[" << i << "][" << j << "] : ";
      cin >> t;
      matrix[i][j] = t;
    }
    cout << endl;
  }

  cal_det(matrix, n, 0, det, 1);

  cout << "determinant is : " << det << endl;
  
  return 0;
}
