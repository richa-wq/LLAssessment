#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
        return nullptr;  // Base case: empty tree
    }

    // If both nodes are smaller than the current node, search in the left subtree
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    // If both nodes are larger than the current node, search in the right subtree
    if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    // If one node is on the left and the other is on the right, or one of them is the current node
    // then the current node is the LCA
    return root;
}

int main() {
    // Example usage:
    // Construct a BST:      5
    //                      /   \
    //                     3     6
    //                    / \   / \
    //                   2   4 5   7
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    TreeNode* p = root->left;   // Node with value 3
    TreeNode* q = root->right;  // Node with value 6

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca) {
        std::cout << "Lowest Common Ancestor: " << lca->val << std::endl;
    } else {
        std::cout << "No common ancestor found." << std::endl;
    }

    // Clean up memory (deallocating nodes)
    // Note: In a real application, you might have a more sophisticated memory management strategy.
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
