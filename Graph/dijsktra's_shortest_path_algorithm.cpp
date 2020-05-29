#include <bits/stdc++.h>

using namespace std;

int min_distance(int dis[], bool vis[], int nodes){
	int min = INT_MAX, index;
	for(int i = 0; i < nodes; i++){
		if(vis[i] == false && dis[i] <= min){
			min = dis[i];
			index = i;
		}
	}
	return index;
}

void shortest_path(int dis[], bool vis[], int nodes, vector<vector<pair<int, int>>> &a, int source){
	int k;
	dis[source] = 0;
	for(int i = 0; i < nodes-1; i++){
		k = min_distance(dis, vis, nodes);
		vis[k] = true;
		for(int j = 0; j < a[k].size(); j++){
			if(!vis[a[k][j].first] && dis[k] != INT_MAX && dis[k] + a[k][j].second < dis[a[k][j].first]){
				dis[a[k][j].first] = dis[k] + a[k][j].second; 
			}
		}
	}
	for(int i = 0; i < nodes; i++){
		cout << dis[i] << " ";
	}
}

int main(){
	int nodes, edges, x, y, weight;
	cin >> nodes >> edges;
	int dis[nodes];
	bool vis[nodes];
	vector<vector<pair<int, int>>> a(nodes);
	for(int i = 0; i < edges; i++){
		cin >> x >> y >> weight;
		x--; y--;
		a[x].push_back(make_pair(y, weight));
		a[y].push_back(make_pair(x, weight));
	}
	for(int i = 0; i < nodes; i++){
		dis[i] = INT_MAX;
		vis[i] = false;
	}
	shortest_path(dis, vis, nodes, a, 0);
	return 0;
}