#include <conio.h>
#include <iostream.h>

void gameOfLife(int** board, int boardSize, int* boardColSize)
{
  const int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
  const int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
  int i, j, k;

  for (i = 0; i < boardSize; i++) {
    for (j = 0; j < *boardColSize; j++) {
      int cnt = 0;
      for (k = 0; k < 8; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || y < 0 || x >= boardSize || y >= *boardColSize)
          continue;
        if (board[x][y] & 1)
          ++cnt;
      }
      if (board[i][j]) {
        if (cnt == 2 || cnt == 3) {
          board[i][j] |= 2;
        }
      } else if (cnt == 3) {
        board[i][j] |= 2;
      }
    }
  }

  for (i = 0; i < boardSize; i++) {
    for (j = 0; j < *boardColSize; j++) {
      board[i][j] = (board[i][j] & 2) >> 1;
    }
  }
}

int main()
{
  int i, j, boardSize = 4, boardColSize = 3;

  int** board = new int*[boardSize];
  for (i = 0; i < boardSize; i++)
    board[i] = new int[boardColSize];

  board[0][0] = 0;
  board[0][1] = 1;
  board[0][2] = 0;
  board[1][0] = 0;
  board[1][1] = 0;
  board[1][2] = 1;
  board[2][0] = 1;
  board[2][1] = 1;
  board[2][2] = 1;
  board[3][0] = 0;
  board[3][1] = 0;
  board[3][2] = 0;


  gameOfLife(board, boardSize, &boardColSize);

  for (i = 0; i < boardSize; i++) {
    for (j = 0; j < boardColSize; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  for (i = 0; i < 3; i++)
    delete[] board[i];
  delete[] board;
  getch();
  return 0;
}
