/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int height(node* root){
    if(root == NULL){
        return -1;
    }
    else{
        return root->ht;
    }
}

int getbalance(node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return (height(root->left) - height(root->right));
    }
}

node* new_node(int key){
    node* t = (node*)malloc(sizeof(node));
    t->val = key;
    t->left = NULL;
    t->right = NULL;
    t->ht = 0;
    return t;
}

node* left_rotate(node* x){
    node* y = x->right;
    node* t = y->left;
    y->left = x;
    x->right = t;
    x->ht = max(height(x->left), height(x->right)) + 1;
    y->ht = max(height(y->left), height(y->right)) + 1;
    return y;
}

node* right_rotate(node* y){
    node* x = y->left;
    node* t = x->right;
    x->right = y;
    y->left = t;
    y->ht = max(height(y->left), height(y->right)) + 1;
    x->ht = max(height(x->left), height(x->right)) + 1;
    return x;
}

node * insert(node * root,int val){
	if(root == NULL){
        return new_node(val);
    }
    if(val < root->val){
        root->left = insert(root->left, val);
    }
    else if(val > root->val){
        root->right = insert(root->right, val);
    }
    else{
        return root;
    }
    
    root->ht = 1 + max(height(root->left), height(root->right));
    int balance = getbalance(root);
    
    if(balance > 1 && val < root->left->val){
        return right_rotate(root);
    }
    if(balance < -1 && val > root->right->val){
        return left_rotate(root);
    }
    if(balance > 1 && val > root->left->val){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance < -1 && val < root->right->val){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}