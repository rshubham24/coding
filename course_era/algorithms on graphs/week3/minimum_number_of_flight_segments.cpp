#include <bits/stdc++.h>

using namespace std;

void bfs(int u, int v, vector<vector<int>> &a, int n){
	vector<int> level(n, -1);
	vector<bool> vis(n, false);
	level[u] = 0;
	queue<int> q;
	q.push(u);
	vis[u] = true;
	while(!q.empty()){
		int k = q.front();
		q.pop();
		for(int i = 0; i < a[k].size(); i++){
			if(!vis[a[k][i]]){
				level[a[k][i]] = level[k] + 1;
				q.push(a[k][i]);
				vis[a[k][i]] = true;
				if(a[k][i] == v){
					cout << level[a[k][i]];
					return;
				}
			}
		}
	}
	cout << -1;
}

int main(){
	int n, m, x, y;
	cin >> n >> m;
	vector<vector<int>> a(n);
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		a[x-1].push_back(y-1);
		a[y-1].push_back(x-1);
	}
	cin >> x >> y;
	bfs(x-1, y-1, a, n);
}