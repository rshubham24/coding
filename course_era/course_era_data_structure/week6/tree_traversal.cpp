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



void in_order(Node* root){
  	if(root == NULL){
  		return;
  	}
  	in_order(root->left);
  	cout << root->data << " ";
  	in_order(root->right);
} 

void pre_order(Node* root){
	if(root == NULL){
		return;
	}
	cout << root->data << " ";
	pre_order(root->left);
	pre_order(root->right);
}

void post_order(Node* root){
	if(root == NULL){
		return;
	}
	post_order(root->left);
	post_order(root->right);
	cout << root->data << " ";
}

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

int main(){
	int n, y, z;
	cin >> n;
	long long x;
	int a[n][3];
	for(int i = 0; i < n; i++){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	Node* root = new Node(a[0][0]);
	insert(a, root, 0);
	in_order(root);
	cout << endl;
	pre_order(root);
	cout << endl;
	post_order(root);
	return 0;
}