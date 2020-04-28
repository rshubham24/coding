// Directed Graph
#include <bits/stdc++.h>

using namespace std;

void bellman_ford(vector<vector<pair<int, int>>> &a, int dis[], int nodes, int edges, int src){
	dis[src] = 0;
	for(int k = 0; k < nodes-1; k++){
		for(int i = 0; i < a.size(); i++){
			for(int j = 0; j < a[i].size(); j++){
				if(dis[a[i][j].first] > dis[i] + a[i][j].second){
					dis[a[i][j].first] = dis[i] + a[i][j].second;
				}
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
	vector<vector<pair<int, int>>> a(nodes);
	int dis[nodes];
	for(int i = 0; i < edges; i++){
		cin >> x >> y >> weight;
		a[x].push_back(make_pair(y, weight));
	}
	for(int i = 0; i < nodes; i++){
		dis[i] = INT_MAX;
	}
	bellman_ford(a, dis, nodes, edges, 0);
}

// Undirected Graph

#include <bits/stdc++.h>

using namespace std;

void bellman_ford(vector<vector<pair<int, int>>> &a, int dis[], int nodes, int edges, int src){
	dis[src] = 0;
	for(int k = 0; k < nodes-1; k++){
		for(int i = 0; i < a.size(); i++){
			for(int j = 0; j < a[i].size(); j++){
				if(dis[a[i][j].first] > dis[i] + a[i][j].second){
					dis[a[i][j].first] = dis[i] + a[i][j].second;
				}
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
	vector<vector<pair<int, int>>> a(nodes);
	int dis[nodes];
	for(int i = 0; i < edges; i++){
		cin >> x >> y >> weight;
		a[x].push_back(make_pair(y, weight));
		a[y].push_back(make_pair(x, weight));
	}
	for(int i = 0; i < nodes; i++){
		dis[i] = INT_MAX;
	}
	bellman_ford(a, dis, nodes, edges, 0);
}