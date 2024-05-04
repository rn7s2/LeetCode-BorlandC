#include <conio.h>
#include <iostream.h>

#define QSIZE 10000

class RecentCounter {
public:
  RecentCounter() : head(0), tail(-1) { }
  int ping(int t);

private:
  int q[QSIZE], head, tail;
};

int RecentCounter::ping(int t) {
  q[++tail] = t;
  while (head < tail && q[head] < t - 3000)
    ++head;
  return tail - head + 1;
}

int main() {
  RecentCounter* obj = new RecentCounter();
  cout << obj->ping(1) << endl;
  cout << obj->ping(100) << endl;
  cout << obj->ping(3001) << endl;
  cout << obj->ping(3002) << endl;

  delete obj;
  getch();
  return 0;
}
