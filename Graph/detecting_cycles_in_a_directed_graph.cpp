#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> &a, vector<bool> &vis, vector<bool> &restack, int k){
	if(!vis[k]){
		vis[k] = true;
		restack[k] = true;
		for(int i = 0; i < a[k].size(); i++){
			if(!vis[a[k][i]] && dfs(a, vis, restack, a[k][i])){
				return true;
			}
			else if(restack[a[k][i]]){
				return true;
			}
		}
	}
	restack[k] = false;
	return false;
}

bool dfs_cyclic(vector<vector<int>> &a, int n){
	vector<bool> vis(n, false);
	vector<bool> restack(n, false);
	for(int i = 0; i < n; i++){
		if(dfs(a, vis, restack, i)){
			return true;
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
	}
	if(dfs_cyclic(a, n)){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}