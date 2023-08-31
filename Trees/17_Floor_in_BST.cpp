// Function to search a node in BST.

int floor(Node* root, int x) {
    // Code here
    int floor = -1;
    while(root){
        if(root->data == x){
            floor = root->data;
            return floor;
        }
        if(root->data > x){
            root = root->left;
        }
        else{
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}
