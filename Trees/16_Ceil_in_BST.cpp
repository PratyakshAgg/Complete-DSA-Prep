// User function Template for C++

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int key) {
    if (root == NULL) return -1;

    // Your code here
    int ceil = -1;
    while(root){
        if(root->data == key){
            ceil = root->data;
            return ceil;
        }
        if(key > root->data){
            root = root->right;
        }
        else {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}