#include <bits/stdc++.h>

using namespace std;

void bridges(vector<vector<int>> &a, vector<bool> &vis, vector<int> &parent, int low[], int disc[], int vertex){
	static int time = 0;
	low[vertex] = disc[vertex] = ++time;
	vis[vertex] = true;
	for(int i = 0; i < a[vertex].size(); i++){
		if(vis[a[vertex][i]] == false){
			parent[a[vertex][i]] = vertex;
			bridges(a, vis, parent, low, disc, a[vertex][i]);
			low[vertex] = min(low[vertex], low[a[vertex][i]]);
			if(low[a[vertex][i]] > disc[vertex]){
			    cout << a[vertex][i] << " " << vertex << endl;
			}
		}
		else if(parent[vertex] != a[vertex][i]){
			low[vertex] = min(low[vertex], disc[a[vertex][i]]);
		}
	}
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
	vector<int> parent(n, -1);
	int low[n], disc[n];
	bridges(a, vis, parent, low, disc, 0);
	return 0;
}