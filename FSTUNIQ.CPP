#include <conio.h>
#include <iostream.h>

int firstUniqChar(char* s)
{
  if (!s)
    return -1;

  char* p;
  int cnt[26] = { 0 };
  for (p = s; *p; ++p)
    ++cnt[*p - 'a'];

  for (p = s; *p; ++p) {
    if (cnt[*p - 'a'] == 1)
      return p - s;
  }
  return -1;
}

int main()
{
  cout << firstUniqChar("leetcode") << endl;
  cout << firstUniqChar("loveleetcode") << endl;
  cout << firstUniqChar("aabb") << endl;

  getch();
  return 0;
}
