from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        l_height = self.maxDepth(root.left)
        r_height = self.maxDepth(root.right)

        return max(l_height, r_height) + 1
