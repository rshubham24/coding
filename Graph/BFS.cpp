#include <bits/stdc++.h>

using namespace std;

void func(vector<vector<int>> &a, int c, int b){
	a[b].push_back(c);
	a[c].push_back(b);
}

void BFS(vector<vector<int>> &a, int b){
	bool vis[6];
	int p;
	for(int i = 0; i < 6; i++){
		vis[i] = false;
 	}
	queue<int> q;
	q.push(b);
	vis[b] = true;
	cout << b << " ";
	while(!q.empty()){
		p = q.front();
		q.pop();
		for(int i = 0; i < a[p].size(); i++){
			if(vis[a[p][i]] == false){
				cout << a[p][i] << " ";
				vis[a[p][i]] = true;
				q.push(a[p][i]);
			}
		}
	}
	cout << endl;
}

int main(){
	vector<vector<int>> a(6);
	func(a, 0, 1);
	func(a, 0, 2);
	func(a, 1, 3);
	func(a, 1, 4);
	func(a, 2, 4);
	func(a, 3, 5);
	func(a, 3, 4);
	func(a, 4, 5);
	BFS(a, 0);
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < a[i].size(); j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}