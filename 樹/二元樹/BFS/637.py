class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        ave = list()
        queue = collections.deque([root])
        while queue:
            total = 0
            size = len(queue)
            for _ in range(size):
                node = queue.popleft()
                total += node.val
                left, right = node.left, node.right 
                if left:
                    queue.append(left)
                if right:
                    queue.append(right)
            ave.append(total / size)
        return ave
