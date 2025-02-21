class FindElements {
    private var values: Set<Int> = []

    init(_ root: TreeNode?) {
        if let root = root {
            recoverTree(root, 0)
        }
    }
    
    private func recoverTree(_ node: TreeNode?, _ val: Int) {
        guard let node = node else { return }
        
        node.val = val
        values.insert(val)
        
        recoverTree(node.left, 2 * val + 1)
        recoverTree(node.right, 2 * val + 2)
    }
    
    func find(_ target: Int) -> Bool {
        return values.contains(target)
    }
}

