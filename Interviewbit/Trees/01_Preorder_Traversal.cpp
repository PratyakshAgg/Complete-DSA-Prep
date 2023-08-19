/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void preorder(TreeNode* root, vector<int> &nodes){
    if(!root) return;
    nodes.push_back(root->val);
    preorder(root->left, nodes);
    preorder(root->right, nodes);
}
 
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> nodes;
    preorder(A, nodes);
    return nodes;
}
