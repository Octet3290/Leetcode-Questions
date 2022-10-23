'''
Given a binary tree, return the inorder traversal of its nodes' values.
For example:
Given binary tree {0,#,1,2},
   0
    \
     1
    /
   2
return [0,2,1].
'''

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.right = None        
        self.left = None


class Solution(object):
    def inorder_Traversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        stack = []
        p = root
        while p or stack:
            # Save the nodes which have left child
            while p:
                stack.append(p)
                p = p.left
            if stack:
                p = stack.pop()
                # Visit the middle node
                result.append(p.val)
                # Visit the right subtree
                p = p.right
        return result


if __name__ == "__main__":
    n1 = TreeNode(0)
    n2 = TreeNode(1)
    n3 = TreeNode(2)
    n1.right = n2
    n2.left = n3
    assert Solution().inorder_Traversal(n1) == [0, 2, 1]
