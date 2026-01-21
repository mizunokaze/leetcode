class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        ans = []
        path = []

        def dfs(node: Optional[TreeNode], left: int) -> None:
            if node is None:
                return
            path.append(node.val)
            left -= node.val 
            if node.left is None and node.right is None and left == 0:
                ans.append(path.copy())
            else:
                dfs(node.left, left)
                dfs(node.right, left)
            path.pop()
        
        dfs(root, targetSum)
        return ans
