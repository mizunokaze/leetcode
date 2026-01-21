class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        if root is None:
            return None 
        left_tail = self.flatten(root.left)
        right_tail = self.flatten(root.right)
        if left_tail:
            left_tail.right = root.right 
            root.right = root.left 
            root.left = None
        return right_tail or left_tail or root
