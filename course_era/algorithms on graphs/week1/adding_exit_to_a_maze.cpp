#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &a, vector<bool> &vis, int src){
	vis[src] = true;
	for(int i = 0; i < a[src].size(); i++){
		if(vis[a[src][i]] == false){
			dfs(a, vis, a[src][i]);
		}
	}
}

int main(){
	int n, count = 0, m, x, y;
	cin >> n >> m;
	vector<vector<int>> a(n);
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		a[x-1].push_back(y-1);
		a[y-1].push_back(x-1);
	}
	vector<bool> vis(n, false);
	for(int i = 0; i < n; i++){
		if(vis[i] == false){
			count++;
			dfs(a, vis, i);
		}
	}
	cout << count;
	return 0;
}