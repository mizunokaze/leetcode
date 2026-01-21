class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        def getMed(left: ListNode, right: ListNode) -> ListNode:
            fast = slow = left
            while fast != right and fast.next != right:
                fast = fast.next.next 
                slow = slow.next 
            return slow 
        
        def bulidT(left: ListNode, right: ListNode) -> TreeNode:
            if left == right:
                return None 
            mid = getMed(left, right)
            root = TreeNode(mid.val)
            root.left = bulidT(left, mid)
            root.right = bulidT(mid.next, right)
            return root 
        
        return bulidT(head, None)
