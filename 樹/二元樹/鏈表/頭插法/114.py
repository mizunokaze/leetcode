class Solution:
    head = None 

    def flatten(self, root: Optional[TreeNode]) -> None:
        if root is None:
            return
        self.flatten(root.right)
        self.flatten(root.left)
        root.left = None 
        root.right = self.head 
        self.head = root     
