#include "global.h"

int main()
{
  int n;
  cout << "Enter Square Size : ";
  // number should be bigger than 1 and odd
  do {
    cin >> n;
  } while (n < 3 || n % 2 == 0);
  int square[n][n] = {0};
  memset(square, 0, sizeof(square[0][0]) * n * n);
  int total_size = n * (n * n + 1 ) / 2;

  int c = 1;
  int x = n / 2, y =  n - 1;
  for (int i = 0; i <= n * n; i++) {
    if (x == -1 && y == n) {
      x = 0;
      y = n - 2;
    } else {
      if (x < 0) {
	x = n - 1;
      }
      if (y == n)
	y = 0;
    }
    if (square[x][y] != 0) {
      x++;
      y -= 2;
      continue;
    } else {
      square[x][y] = c++;
    }
    x--;
    y++;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << square[i][j] << '\t';
    }
    cout << endl;
  }

  return 0;
}
