/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> traversal;
        inorder(root, traversal);

        int l = 0, r = traversal.size() - 1;
        while(l < r){
            if(traversal[l] + traversal[r] == k) return true;
            else if(traversal[l] + traversal[r] > k) r--;
            else l++;
        }
        return false;
    }

    void inorder(TreeNode *root, vector<int> &traversal){
        if(!root) return;
        inorder(root->left, traversal);
        traversal.push_back(root->val);
        inorder(root->right, traversal);
    }
};