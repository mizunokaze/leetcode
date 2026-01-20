class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        ans = []

        def dfs(node: Optional[TreeNode], path: str) -> None:
            if node is None:
                return
            path += str(node.val)
            if node.left is None and node.right is None:
                ans.append(path)
                return
            path += "->"
            dfs(node.left, path)
            dfs(node.right, path)

        dfs(root, "")
        return ans
