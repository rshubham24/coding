#include <bits/stdc++.h> 

using namespace std;

struct Node { 
  	int data; 
  	Node *left, *right; 
  	Node (int x){ 
    data = x; 
    left = right = NULL; 
  	} 
};

void insert(int a[][3], Node* root, int s){
	if(a[s][1] != -1){
		root->left = new Node(a[a[s][1]][0]);
		insert(a, root->left, a[s][1]);
	}
	if(a[s][2] != -1){
		root->right = new Node(a[a[s][2]][0]);
		insert(a, root->right, a[s][2]);
	}
	else{
		return;
	}
}

bool bst(Node* root, int a, int b){
	if(root == NULL){
		return true;
	}
	if(root->data < a || root->data > b){
		return false;
	}
	return bst(root->left, a, root->data - 1) && bst(root->right, root->data + 1, b);
}

int main(){
	int n, y, z;
	cin >> n;
	if(n != 0){
		int a[n][3];
		for(int i = 0; i < n; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		Node* root = new Node(a[0][0]);
		insert(a, root, 0);
		if(bst(root, INT_MIN, INT_MAX)){
			cout << "CORRECT";
		}
		else{
			cout << "INCORRECT";
		}
	}
	else{
		cout << "CORRECT";
	}
	return 0;
}