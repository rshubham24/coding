#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>> &a, int x, int y, int n){
	vector<bool> vis(n, false);
	queue<int> q;
	q.push(x);
	int p;
	vis[x] = true;
	while(!q.empty()){
	    p = q.front();
	    q.pop();
		for(int i = 0; i < a[p].size(); i++){
			if(a[p][i] == y){
				return true;
			}
			if(vis[a[p][i]] == false){
				q.push(a[p][i]);
				vis[a[p][i]] = true;
			}
		}
	}
	return false;
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
	if(bfs(a, x-1, y-1, n)){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}