#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream.h>

typedef int bool;

bool isValid(char* s)
{
  if (!s || s[0] == '\0')
    return 1;

  char* stack = (char*)malloc(strlen(s) * sizeof(char));
  int top = -1;

  for (char* p = s; *p; p++) {
    char ch = *p;
    if (ch == '(' || ch == '[' || ch == '{') {
      stack[++top] = ch;
    } else {
      if (top < 0) {
        free(stack);
        return 0;
      }
      char t = stack[top--];
      if (ch == ')' && t == '(') {
      } else if (ch == ']' && t == '[') {
      } else if (ch == '}' && t == '{') {
      } else {
        free(stack);
        return 0;
      }
    }
  }

  free(stack);
  return top == -1;
}

int main()
{
  cout << isValid("()") << endl;
  cout << isValid("()[]{}") << endl;
  cout << isValid("(]") << endl;

  getch();
  return 0;
}
