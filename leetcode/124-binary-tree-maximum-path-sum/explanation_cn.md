# 124. Binary Tree Maximum Path Sum

## 解析

首先注意到，二叉树里的最大的路径和不一定要通过根节点。

考察一般情况，对于经过某一个节点的路径和有两种可能：

1. 来自这个节点的左子树，穿过这个节点，然后通往这个节点的右子树。
2. 来自这个节点的某一个子树，穿过这个节点，然后通往这个节点的父节点。

对于第一种情况，路径和等于左子树的路径和，加上右子树的路径和，加上当前节点的权重。我们算出了这条路径的总和，可以用来更新全局的最大值。对于第二种情况，我们无法获悉父节点上的路径和，所以只能把当前节点已知的路径和求出，返回给上层继续处理。当前节点的路径和是左右子树路径和里较大的那个，加上当前节点的权重。

这道题里，虽然节点的权重可以是负数，但是并不需要做特殊处理。
