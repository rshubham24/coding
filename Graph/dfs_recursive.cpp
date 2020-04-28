#include <bits/stdc++.h>

using namespace std;

void func(vector<vector<int>> &a, int c, int b){
	a[b].push_back(c);
	a[c].push_back(b);
}

bool vis[5];

void f(){
	for(int i = 0; i < 5; i++){
		vis[i] = false;
	}
}

void DFS(vector<vector<int>> &a, int b){
	vis[b] = true;
	cout << b << " ";
	for(int i = 0; i < a[b].size(); i++){
		if(vis[a[b][i]] == false){
			DFS(a, a[b][i]);
		}
	}
}

int main(){
	vector<vector<int>> a(5);
	func(a, 0, 1);
	func(a, 0, 2);
	func(a, 1, 3);
	func(a, 1, 4);
	DFS(a, 0);
	cout << endl;
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < a[i].size(); j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}