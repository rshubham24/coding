#include <bits/stdc++.h>

using namespace std;

int n;

void reverse_dfs(vector<vector<int>> &b, vector<bool> &vis, int k){
	vis[k] = true;
	cout << k << " ";
	for(int i = 0; i < b[k].size(); i++){
		if(!vis[b[k][i]]){
			reverse_dfs(b, vis, b[k][i]);
		}
	}
}

void reverse(vector<vector<int>> &b, vector<vector<int>> &a){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < a[i].size(); j++){
			b[a[i][j]].push_back(i);
		}
	}
}

void fill_stack(vector<vector<int>> &a, int v, stack<int> &s, vector<bool> &vis){
	vis[v] = true;
	for(int i = 0; i < a[v].size(); i++){
		if(!vis[a[v][i]]){
			fill_stack(a, a[v][i], s, vis);
		}
	}
	s.push(v);
}

void print_scc(vector<vector<int>> &a){
	stack<int> s;
	vector<bool> vis(n, false);
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			fill_stack(a, i, s, vis);
		}
	}
	vector<vector<int>> b(n);
	reverse(b, a);
	for(int i = 0; i < n; i++){
		vis[i] = false;
	}
	while(!s.empty()){
		int k = s.top();
		s.pop();
		if(!vis[k]){
			reverse_dfs(b, vis, k);
			cout << endl;
		}
	}
}

int main(){
	int m, x, y;
	cin >> n >> m;
	vector<vector<int>> a(n);
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		a[x].push_back(y);
	}
	print_scc(a);
	return 0;
}