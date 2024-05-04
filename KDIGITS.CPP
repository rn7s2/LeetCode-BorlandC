#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream.h>

char* removeKdigits(char* num, int k)
{
  char* stack = (char*)malloc(strlen(num) * sizeof(char));
  int top = -1;

  for (char* p = num; *p; p++) {
    char ch = *p;
    if (top == -1 || stack[top] <= ch) {
      stack[++top] = ch;
    } else {
      while (top >= 0 && stack[top] > ch && k > 0)
        --top, --k;
      stack[++top] = ch;
    }
  }
  while (top >= 0 && k > 0)
    --top, --k;
  if (top == -1)
    stack[++top] = '0';

  int leadingZeroes = 0;
  while (leadingZeroes < top && stack[leadingZeroes] == '0')
    leadingZeroes++;

  num[top - leadingZeroes + 1] = '\0';
  while (top >= leadingZeroes)
    num[top - leadingZeroes] = stack[top], --top;

  free(stack);
  return num;
}

int main()
{
  cout << removeKdigits("1432219", 3) << endl;
  cout << removeKdigits("10200", 1) << endl;
  cout << removeKdigits("10", 2) << endl;
  cout << removeKdigits("9", 1) << endl;

  getch();
  return 0;
}
