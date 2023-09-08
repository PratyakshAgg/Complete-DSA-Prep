/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    bool isLeaf(Node* root){
        if(!root->left and !root->right) return true;
        else return false;
    }
    
    void addLeftBoundary(Node* root, vector<int> &nodes){
        Node* curr = root->left;
        while(curr){
            if(!isLeaf(curr)) nodes.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void addRightBoundary(Node* root, vector<int> &nodes){
        Node* curr = root->right;
        vector<int> tmp;
        while(curr){
            if(!isLeaf(curr)) tmp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for(int i = tmp.size()-1; i >= 0; i--) nodes.push_back(tmp[i]);
    }
    
    void addLeaves(Node* root, vector<int> &nodes){
        if(isLeaf(root)){
            nodes.push_back(root->data);
            return;
        }
        if(root->left) addLeaves(root->left, nodes);
        if(root->right) addLeaves(root->right, nodes);
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> nodes;
        if(!root) return nodes;
        if(!isLeaf(root)) nodes.push_back(root->data);
        addLeftBoundary(root, nodes);
        addLeaves(root, nodes);
        addRightBoundary(root, nodes);
        return nodes;
    }
};