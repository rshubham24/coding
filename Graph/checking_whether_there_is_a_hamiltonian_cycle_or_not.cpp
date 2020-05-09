#include <bits/stdc++.h>

using namespace std;
int k = 0, start;

void hamiltonian(vector<vector<int>> &a, vector<int> &path, vector<bool> &vis, int v, int n){
	if(path.size() == n){
		for(int i = 0; i < a[path[path.size()-1]].size(); i++){
			if(a[path[path.size()-1]][i] == start){
				k++;
			}
		}
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
	start = 0;
	path.push_back(start);
	vis[start] = true;
	hamiltonian(a, path, vis, start, n);
	if(k == 0){
		cout << "No Hamiltonian Cycle";
	}
	else{
		cout << "Hamiltonian Cycle Present";
	}
	return 0;
}