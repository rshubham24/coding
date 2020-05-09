#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>> &r, int n, int s, int t, int parent[]){
	vector<bool>vis(n, false);
	parent[s] = -1;
	queue<int> q;
	int k;
	q.push(s);
	vis[s] = true;
	while(!q.empty()){
		k = q.front();
		q.pop();
		for(int i = 0; i < n; i++){
			if(!vis[i] && r[k][i] > 0){
				parent[i] = k;
				q.push(i);
				vis[i] = true;
			}
		}
	}
	return vis[t];
}

int max_flow(vector<vector<int>> &a, int n, int s, int t){
	int x, y;
	vector<vector<int>> r(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			r[i].push_back(a[i][j]);
		}
	}
	int parent[n], flow = 0, j;
	while(bfs(r, n, s, t, parent)){
		int path_flow = INT_MAX;
		for(int i = t; i!= s; i = parent[i]){
			j = parent[i];
			path_flow = min(path_flow, r[j][i]);
		}
		for(int i = t; i!= s; i = parent[i]){
			j = parent[i];
			r[j][i] -= path_flow;
			r[i][j] += path_flow; 
		}
		flow += path_flow;
	}
	return flow;
}

int main(){
	int n, m, x, y, w, s, t;
	cin >> n >> m >> s >> t;
	vector<vector<int>> a(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i].push_back(0);
		}
	} 
	for(int i = 0; i < m; i++){
		cin >> x >> y >> w;
		a[x][y] = (w);
	}
	cout << max_flow(a, n, s, t);
	return 0;
}