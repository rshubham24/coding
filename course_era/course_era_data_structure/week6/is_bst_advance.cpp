#include <bits/stdc++.h> 

using namespace std;

long long l = -214748364885974, m = 214748364885974;

struct Node { 
  	long long data; 
  	Node *left, *right; 
  	Node (long long x){ 
    data = x; 
    left = right = NULL; 
  	} 
};

void insert(long long a[][3], Node* root, long long s){
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

bool bst(Node* root, long long a, long long b){
	if(root == NULL){
		return true;
	}
	if(root->data < a || root->data > b){
		return false;
	}
	return bst(root->left, a, root->data - 1) && bst(root->right, root->data, b);
}

int main(){
	long long n;
	cin >> n;
	if(n != 0){
		long long a[n][3];
		for(long long i = 0; i < n; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];				
		}
		Node* root = new Node(a[0][0]);
		insert(a, root, 0);
		if(bst(root, l, m)){
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