map<int, int> a;
map<int, int> b;
int min = INT_MAX, max = INT_MIN, t = 0, s = INT_MIN;
void topview1(Node* root, int i, Node* current){
    if(root != NULL && root->data == current->data && t == 0){
        t = 1;
    }
    if(root != NULL && t == 0){
        if(i < min){
            min = i;
        }
        if(i > s){
            s = i;
        }
        if(i <= 0){
            a.insert(pair<int, int>(i, root->data));
        }
        if(i > 0){
            b[i] = root->data;
        }
    }
    if(root != NULL && t == 1){
        if(i < min){
            min = i;
        }
        if(i > max){
            max = i;
        }
        a.insert(pair<int, int>(i, root->data));
    }
    if(root == NULL){
        return;
    }
    if(i <= 0){
    topview1(root->left, i - 1, current);
    topview1(root->right, i + 1, current);
    }
    else{
    topview1(root->right, i + 1, current);
    topview1(root->left, i - 1, current);
    }
}

void topView(Node* root) {
    Node* current = root->right;
    topview1(root, 0, current);
    map<int, int>::iterator itr;
    for(int i = min; i <= max; i++){
        itr = a.find(i);
        cout << itr->second << " ";
    }
    for(int i = max + 1; i <= s; i++){
        itr = b.find(i);
        cout << itr->second << " ";
    }
