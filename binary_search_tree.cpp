// It is called Balanced Binary Search Tree
/*
TIME COMPLEXITY FOR SEARCH IS O(log n)
TIME COMPLEXITY FOR insert IS O(log n)
TIME COMPLEXITY FOR delete  IS O(log n)
*/
// Searching of key in Bst
struct node* search(struct node* root,int key){
    if(root==NULL or root->key==key) return root;
    if(root->key<key) return search(root->right,key);
    return search(root->left,key);
}
// For Insertion in Bst
class BST{
    int data;
    BST *left,*right;
    public:
        // Default constructor
        BST();
        // Parameterised Constructor
        BST(int);
        // Insert Func
        BST* Insert(BST*,int);
        void Inorder(BST*);
};
// Default constructor definition
BST::BST():data(0),left(NULL),right(NULL){}
// Parameterised constructor definition
BST::BST(int val){
    data=val;
    left=right=NULL;
}
// Insert Function
BST* BST:: Insert(BST* root,int val){
    if(!root) return new BST(val);
    if(val>root->data) root->right=Insert(root->right,val);
    else root->left=Insert(root->left,val);
    return root;
}
void BST::Inorder(BST* root){
    if(!root) return;
    Inorder(root->left);
    cout<<root->data<<endl;
    Inorder(root->right);
}
int main(){
    BST b,*root=NULL;
    root=b.Insert(root,50);
    b.Insert(root,20);
    b.Inorder(root);
    return 0;
}