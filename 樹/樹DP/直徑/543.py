class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def dfs(node: Optional[TreeNode]) -> int:
            if node is None:
                return -1
            le_len = dfs(node.left) + 1
            ri_len = dfs(node.right) + 1
            nonlocal ans
            ans = max(ans, le_len + ri_len)
            return max(le_len, ri_len)
        dfs(root)
        return ans
