#include <bits/stdc++.h> 

using namespace std; 
	 
int V; 

#define INF INT_MAX

bool floydWarshall(vector<vector<int>> &graph){ 
	int dist[V][V], i, j, k; 
	for(i = 0; i < V; i++){ 
		for(j = 0; j < V; j++){ 
			dist[i][j] = graph[i][j];
		}
	}		 
	for(k = 0; k < V; k++){ 
		for(i = 0; i < V; i++){ 
			for(j = 0; j < V; j++){ 
				if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];	
				}  
			} 
		} 
	}
	for(int i = 0; i < V; i++){ 
        if(dist[i][i] < 0){ 
        	return true;
        }
    } 
    return false; 
} 
	 
int main(){
	int m, x, y, w;
	cin >> V >> m;
	vector<vector<int>> graph(V);
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			if(i == j){
				graph[i].push_back(0);
			}
			else{
				graph[i].push_back(INF);
			}
		}
	}
	for(int i = 0; i < m; i++){
		cin >> x >> y >> w;
		graph[x-1][y-1] = w;
	}
	if(floydWarshall(graph)){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0; 
}