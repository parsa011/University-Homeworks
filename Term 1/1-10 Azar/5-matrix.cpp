#include <iostream>

using namespace std;

#define ROW 5
#define COL 4

#define GET_MATRIX(matrix, op) {                          \
    cout << "Enter Matrix Elements\n";                    \
    int n = 0;                                            \
    for (int i = 0; i < ROW; i++) {                       \
      for (int j = 0; j < COL; j++) {                     \
        cout << "matrix[" << i << "][" << j << "] :";     \
        cin >> n;                                         \
        matrix[i][j] op n;                                \
      }                                                   \
    cout << '\n';                                         \
  }                                                       \
}

void show_matrix(int matrix[ROW][COL])
{
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      cout << matrix[i][j] << '\t';
    }
    cout << '\n';
  }
  
}

int main()
{
  int result[ROW][COL];
  memset(result, 0, sizeof(result));
  GET_MATRIX(result, +=);
  GET_MATRIX(result, +=);
  show_matrix(result);
  return 0;
}
