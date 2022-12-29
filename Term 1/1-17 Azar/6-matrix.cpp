#include <iostream>

using namespace std;

#define TWO_D_POS(arr, i, j, row) (arr + i * row + j)

void get_matrix(int *matrix, int rows, int cols)
{
  cout << "Enter Your Matrix : \n";
  int n;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << "matrix[" << i << "][" << j << "] : ";
      cin >> n;
      *(TWO_D_POS(matrix, i, j, rows)) = n;
    }
    cout << endl;
  }
}

void multiply_matrix(int *matrix_a, int a_row, int a_col, int *matrix_b, int b_row, int b_col)
{
  if (a_row == b_col) {
    for (int i = 0; i < a_row; i++) {
      for (int j = 0; j < a_col; j++) {
	cout << *TWO_D_POS(matrix_a, i, j, a_row) * *TWO_D_POS(matrix_b, j, i, b_row) << '\t';
      }
      cout << endl;
    }
  } else
    cout << "Can't Multiply Matrixes\n";
}

int main()
{
  int matrix_a_row, matrix_a_col;
  int matrix_b_row, matrix_b_col;
  cout << "Enter First Matrix Row and Col length : \n";
  cin >> matrix_a_row >> matrix_a_col;
  cout << "Enter Second Matrix Row and Col Lnegth : \n";
  cin >> matrix_b_row >> matrix_b_col;
  int matrix_a[matrix_a_row][matrix_a_col], matrix_b[matrix_b_row][matrix_b_col];
  get_matrix(matrix_a[0], matrix_a_row, matrix_a_col);
  get_matrix(matrix_b[0], matrix_b_row, matrix_b_col);
  multiply_matrix(matrix_a[0], matrix_a_row, matrix_a_col, matrix_b[0], matrix_b_row, matrix_b_col);
  return 0;
}
