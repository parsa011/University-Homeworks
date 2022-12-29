#include <iostream>

using namespace std;

#define GET_MATRIX(matrix, row, col, op) {		  \
    cout << "Enter Matrix Elements\n";                    \
    int n = 0;                                            \
    for (int i = 0; i < row; i++) {                       \
      for (int j = 0; j < col; j++) {                     \
        cout << "matrix[" << i << "][" << j << "] : ";    \
        cin >> n;                                         \
        matrix[i][j] op n;                                \
      }                                                   \
    cout << '\n';                                         \
  }                                                       \
}


int main()
{
  int row, col;
  cout << "Enter Row and Col : \n";
  cin >> row >> col;
  int result[row][col];
  memset(result, 0, sizeof(result));
  GET_MATRIX(result, row, col, +=);
  GET_MATRIX(result, row, col, +=);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << result[i][j] << '\t';
    }
    cout << '\n';
  }
  return 0;
}
