#include <conio.h>
#include <stdlib.h>
#include <iostream.h>

struct TreeNode {
  int val;
  struct TreeNode *left, *right;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
  if (!root) {
    *returnSize = 0;
    return NULL;
  }

  int leftSize, rightSize;
  int* left = inorderTraversal(root->left, &leftSize);
  int* right = inorderTraversal(root->right, &rightSize);

  *returnSize = leftSize + rightSize + 1;

  int* all = (int*)malloc(*returnSize * sizeof(int));
  int i = 0, cnt = 0;
  for (i = 0; i < leftSize; i++)
    all[cnt++] = left[i];
  free(left);

  all[cnt++] = root->val;

  for (i = 0; i < rightSize; i++)
    all[cnt++] = right[i];
  free(right);

  return all;
}

int main()
{
  return 0;
}
