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
    vector<TreeNode*> solve(int s, int e){
        vector<TreeNode*> v;

        if(s > e){
            v.push_back(NULL);
            return v;
        }

        for(int i = s; i <= e; i++){
            vector<TreeNode*> left = solve(s, i-1);
            vector<TreeNode*> right = solve(i+1, e);

            for(int j = 0; j < left.size(); j++){
                for(int k = 0; k < right.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    v.push_back(root);
                }
            }
        }
        return v;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};