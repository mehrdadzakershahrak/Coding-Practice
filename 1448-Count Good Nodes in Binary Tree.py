def goodNodes(self, root: TreeNode) -> int:
    return self.dfs(root, float('-inf'))

def dfs(self, node: TreeNode, max_val: int) -> int:
    if node is None:
        return 0
    max_val = max(max_val, node.val)
    return (node.val >= max_val) + self.dfs(node.left, max_val) + self.dfs(node.right, max_val)
