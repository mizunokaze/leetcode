class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        def dfs(node: Optional[TreeNode]) -> None:
            if node is None:
                return
            dfs(node.left)
            dfs(node.right)

            left = node.left
            if left and left.left is None and left.right is None:
                nonlocal ans
                ans += left.val 

        ans = 0
        dfs(root)
        return ans
