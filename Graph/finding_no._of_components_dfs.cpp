#include <bits/stdc++.h>

using namespace std;

void func(vector<vector<int>> &a, int c, int b){
	a[b].push_back(c);
	a[c].push_back(b);
}

bool vis[7];

void f(){
	for(int i = 0; i < 7; i++){
		vis[i] = false;
	}
}

void DFS(vector<vector<int>> &a, int b){
	vis[b] = true;
	for(int i = 0; i < a[b].size(); i++){
		if(vis[a[b][i]] == false){
			DFS(a, a[b][i]);
		}
	}
}

int main(){
	int nodes = 6, count = 0;
	vector<vector<int>> a(7);
	func(a, 1, 2);
	func(a, 2, 3);
	func(a, 1, 3);
	func(a, 4, 5);
	for(int i = 1; i <= nodes; i++){
		if(vis[i] == false){
			DFS(a, i);
			count++;
		}
	}
	cout << count;
	return 0;
}