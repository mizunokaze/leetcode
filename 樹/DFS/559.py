class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root is None:
            return 0
        depth = 1
        for node in root.children:
            depth = max(depth, self.maxDepth(node) + 1)
        return depth
