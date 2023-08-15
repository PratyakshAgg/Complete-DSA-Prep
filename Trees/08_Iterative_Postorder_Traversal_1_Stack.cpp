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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> nodes;
        if(!root) return nodes;
        while(!st.empty() || root != NULL){
            if(root != NULL){
                st.push(root);
                root = root->left;
            }
            else{
                TreeNode* temp = st.top()->right;
                if(!temp){
                    temp = st.top();
                    st.pop();
                    nodes.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        nodes.push_back(temp->val);
                    }
                }
                else{
                    root = temp;
                }
            }
        }
        return nodes;
    }
};