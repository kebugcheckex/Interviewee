#include "header.h"
#include "utils.h"

class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    maxSum_ = numeric_limits<int>::min();
    search(root);
    return maxSum_;
  }

  // returns the max sum of any path under this node (using this node as the
  // root)
  int search(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int maxLeft = max(search(root->left), 0);
    int maxRight = max(search(root->right), 0);
    int currentMax = maxLeft + root->val + maxRight;
    maxSum_ = max(maxSum_, currentMax);
    return max(maxLeft, maxRight) + root->val;
  }

 private:
  int maxSum_;
};
