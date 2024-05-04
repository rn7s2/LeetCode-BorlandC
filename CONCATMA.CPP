#include <conio.h>
#include <stdlib.h>
#include <iostream.h>

typedef int bool;

template<class T>
T max(const T& a, const T& b)
{
  return a > b ? a : b;
}

int* maxPart(int* nums, int len, int k, int* retSize)
{
  *retSize = 0;
  if (k == 0 || k > len)
    return NULL;
  int* stack = (int*)malloc(k * sizeof(int));
  int top = -1, remain = len - k;

  for (int i = 0; i < len; i++) {
    while (top >= 0 && stack[top] < nums[i] && remain > 0)
      --top, --remain;
    if (top + 1 < k)
      stack[++top] = nums[i];
    else
      --remain;
  }

  *retSize = top + 1;
  return stack;
}

bool larger(int* n1, int len1, int* n2, int len2)
{
  if (!n1)
    return 0;
  if (!n2)
    return 1;

  int i, j;
  for (i = 0, j = 0; i < len1 && j < len2; i++, j++) {
    if (n1[i] > n2[j])
      return 1;
    else if (n1[i] < n2[j])
      return 0;
  }
  if (i == len1)
    return 0;
  return 1;
}

int* merge(int* p1, int n, int* p2, int m)
{
  if (n == 0) return p2;
  if (m == 0) return p1;
  int* ret = (int*)malloc((n + m) * sizeof(int));
  int i = 0, j = 0;
  for (int cnt = 0; cnt < n + m; cnt++) {
    if (larger(p1 + i, n - i, p2 + j, m - j))
      ret[cnt] = p1[i++];
    else
      ret[cnt] = p2[j++];
  }

  if (p1) free(p1);
  if (p2) free(p2);
  return ret;
}

int* maxNumber(int* nums1, int m,
               int* nums2, int n,
               int k, int* returnSize)
{
  int i, j;

  int* maxNum = NULL;
  for (int x = 0; x <= k; x++) {
    int y = k - x;
    int len1, len2;
    int* p1 = maxPart(nums1, m, x, &len1);
    int* p2 = maxPart(nums2, n, y, &len2);
    if (len1 + len2 < k)
      continue;
    int* merged = merge(p1, x, p2, y);
    if (larger(merged, k, maxNum, k)) {
      if (maxNum) free(maxNum);
      maxNum = merged;
    }
  }
  *returnSize = k;

  return maxNum;
}

int main()
{
  int nums1[] = { 6, 7 };
  int nums2[] = { 6, 0, 4 };
  int k = 5;

  int retSize;
  int* ret = maxNumber(nums1, sizeof(nums1) / sizeof(int),
                       nums2, sizeof(nums2) / sizeof(int),
                       k, &retSize);
  for (int i = 0; i < retSize; i++)
    cout << ret[i] << " ";
  cout << endl;
  free(ret);

  getch();
  return 0;
}
