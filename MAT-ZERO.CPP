#include <conio.h>
#include <iostream.h>

void setZeroes(int** mat, int n, int* pm)
{
  int i, j, k, col0 = 0, row0 = 0;

  for (i = 0; i < n; i++)
    col0 |= (mat[i][0] == 0);
  for (j = 0; j < *pm; j++)
    row0 |= (mat[0][j] == 0);

  for (i = 1; i < n; i++) {
    for (j = 1; j < *pm; j++) {
      if (mat[i][j] == 0) {
        mat[0][j] = mat[i][0] = 0;
      }
    }
  }

  for (i = 1; i < n; i++) {
    if (mat[i][0] == 0) {
      for (j = 1; j < *pm; j++)
        mat[i][j] = 0;
    }
  }
  for (j = 1; j < *pm; j++) {
    if (mat[0][j] == 0) {
      for (i = 1; i < n; i++)
        mat[i][j] = 0;
    }
  }

  if (col0) {
    for (i = 0; i < n; i++)
      mat[i][0] = 0;
  }
  if (row0) {
    for (j = 0; j < *pm; j++)
      mat[0][j] = 0;
  }
}

int main()
{
  int i, j, n = 3, m = 3;
  int** mat = new int*[n];
  for (i = 0; i < n; i++)
    mat[i] = new int[m];

  mat[0][0] = 1;
  mat[0][1] = 1;
  mat[0][2] = 1;
  mat[1][0] = 1;
  mat[1][1] = 0;
  mat[1][2] = 1;
  mat[2][0] = 1;
  mat[2][1] = 1;
  mat[2][2] = 1;

  setZeroes(mat, n, &m);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }

  for (i = 0; i < n; i++)
    delete[] mat[i];
  delete[] mat;
  getch();
  return 0;
}
