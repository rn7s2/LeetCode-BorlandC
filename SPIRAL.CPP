#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int* spiralOrder(int** matrix,
		 int matrixSize,
		 int* matrixColSize,
		 int* returnSize)
{
  const int impossible = -101;

  if (matrixSize == 0 || *matrixColSize == 0)
    return NULL;
  int* ret = (int*)malloc(matrixSize * (*matrixColSize) * sizeof(int));

  int i = 0, j = 0, cnt = 0;
  while (cnt < matrixSize * (*matrixColSize)) {
    while (j < *matrixColSize && matrix[i][j] != impossible)
      ret[cnt++] = matrix[i][j], matrix[i][j++] = impossible;
    --j, ++i;

    while (i < matrixSize && matrix[i][j] != impossible)
      ret[cnt++] = matrix[i][j], matrix[i++][j] = impossible;
    --i, --j;

    while (j >= 0 && matrix[i][j] != impossible)
      ret[cnt++] = matrix[i][j], matrix[i][j--] = impossible;
    ++j, --i;

    while (i >= 0 && matrix[i][j] != impossible)
      ret[cnt++] = matrix[i][j], matrix[i--][j] = impossible;
    ++i, ++j;
  }

  *returnSize = cnt;
  return ret;
}

int main()
{
  int i, j;
  int** matrix = new int*[3];
  for (i = 0; i < 3; i++) {
    matrix[i] = new int[3];
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      matrix[i][j] = i * 3 + j + 1;
    }
  }

  int colSize = 3;
  int retSize = 0;
  int* ret = spiralOrder(matrix, 3, &colSize, &retSize);
  for (i = 0; i < retSize; i++) {
    cout << ret[i] << " ";
  }
  cout << endl;

  if (ret) {
    free(ret);
  }

  for (i = 0; i < 3; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;

  getch();
  return 0;
}
