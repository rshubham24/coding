#include <bits/stdc++.h>

using namespace std;

int min_distance(vector<int> &dis, vector<bool> &vis, int nodes){
	int min = INT_MAX, index;
	for(int i = 0; i < nodes; i++){
		if(vis[i] == false && dis[i] < min){
			min = dis[i];
			index = i;
		}
	}
	if(min == INT_MAX){
	    return -1;
	}
	else{
	    return index;
	}
}

pair<int, bool> bfs(int n, vector<vector<pair<int, int>>> &a, int source, int des, vector<int> &r){
	vector<bool> vis(n, false);
	vector<int> dis(n, INT_MAX);
	int k;
	dis[source] = 0;
	for(int i = 0; i < n-1; i++){
		k = min_distance(dis, vis, n);
		if(k == -1){
		    return make_pair(0, false);
		}
		if(k == des){
			return make_pair(dis[des], true);
		}
		vis[k] = true;
		for(int j = 0; j < n; j++){
			if(!vis[j] && a[k][j].first > 0 && dis[k] != INT_MAX && dis[k] + a[k][j].second < dis[j]){
				dis[j] = dis[k] + a[k][j].second;
				r[j] = k;
			}
		}
	}
	if(dis[des] != INT_MAX){
	    return make_pair(dis[des], true);
	}
	return make_pair(0, false);
}

pair<int, int> max_flow(vector<vector<pair<int, int>>> &a, int n, int s, int t){
	int x, y;
	vector<vector<pair<int, int>>> r(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			r[i].push_back(a[i][j]);
		}
	}
	vector<int> parent(n, -1);
	int flow = 0, j, cost = 0, f = 8;
	pair<int, bool> q;
	q = bfs(n, r, s, t, parent);
	while(q.second){
		int path_flow = INT_MAX;
		for(int i = t; i!= s; i = parent[i]){
			j = parent[i];
			path_flow = min(path_flow, r[j][i].first);
		}
		for(int i = t; i!= s; i = parent[i]){
			j = parent[i];
			r[j][i].first -= path_flow;
			r[i][j].first += path_flow; 
		}
		flow += path_flow;
		cost += q.first;
		q = bfs(n, r, s, t, parent);
	}
	return make_pair(flow, cost);
}

int main(){
	int n, m, x, y, w, s, t, cost;
	pair<int, int> q;
	cin >> n >> m >> s >> t;
	vector<vector<pair<int, int>>> a(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i].push_back(make_pair(0, 0));
		}
	}
	for(int i = 0; i < m; i++){
		cin >> x >> y >> w >> cost;
		q = make_pair(w, cost);
		a[x][y] = q;
	}
	q = max_flow(a, n, s, t);
	cout << q.first << " " << q.second;
	return 0;
}