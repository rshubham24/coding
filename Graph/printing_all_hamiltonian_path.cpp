#include <bits/stdc++.h>

using namespace std;

void hamiltonian(vector<vector<int>> &a, vector<int> &path, vector<bool> &vis, int v, int n){
	if(path.size() == n){
		for(int x : path){
			cout << x << " ";
		}
		cout << endl;
		return;
	}
	for(int i = 0; i < a[v].size(); i++){
		if(!vis[a[v][i]]){
			vis[a[v][i]] = true;
			path.push_back(a[v][i]);
			hamiltonian(a, path, vis, a[v][i], n);
			vis[a[v][i]] = false;
			path.pop_back();
		}
	}
	return;
}

int main(){
	int n, m, x, y;
	cin >> n >> m;
	vector<vector<int>> a(n);
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	vector<bool> vis(n, false);
	vector<int> path;
	path.push_back(0);
	vis[0] = true;
	hamiltonian(a, path, vis, 0, n);
	return 0;
}