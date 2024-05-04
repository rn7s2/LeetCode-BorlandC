#include <conio.h>
#include <stdlib.h>
#include <iostream.h>

char* removeDuplicateLetters(char* s)
{
  char* p;
  int rem[26] = {0}, vis[26] = {0};
  for (p = s; *p; p++)
    ++rem[*p - 'a'];

  int len = p - s;
  char* stack = (char*)malloc(len * sizeof(char));
  int top = -1;

  for (p = s; *p; ++p) {
    char ch = *p;
    if (!vis[ch - 'a']) {
      while (top >= 0 && stack[top] > ch) {
        if (rem[stack[top] - 'a'] == 0)
          break;
        vis[stack[top--] - 'a'] = 0;
      }
      vis[ch - 'a'] = 1;
      stack[++top] = ch;
    }
    --rem[ch - 'a'];
  }

  int i;
  for (i = 0; i <= top; i++)
    s[i] = stack[i];
  s[i] = '\0';
  free(stack);

  return s;
}

int main()
{
  cout << removeDuplicateLetters("bcabc") << endl;
  cout << removeDuplicateLetters("cbacdcbc") << endl;
  cout << removeDuplicateLetters("cdadabcc") << endl;

  getch();
  return 0;
}
