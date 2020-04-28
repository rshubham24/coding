#include <bits/stdc++.h> 

using namespace std; 
	 
long long V; 

long long INF = 2147483647545;

void floydWarshall(vector<vector<long long>> &graph, long long x){ 
	long long dist[V][V], i, j, k; 
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
	for(i = 0; i < V; i++){ 
        if(dist[i][i] < 0){ 
        	dist[x][i] = dist[i][i];
        }
    }
    for(i = 0; i < V; i++){
        if(x == i){
            cout << 0;
        }
        else if(dist[x][i] < 0){
            cout << "-";
        }
        else if(dist[x][i] == INF){
            cout << "*";
        }
        else{
            cout << dist[x][i];
        }
        cout << endl;
    }
}
	 
int main(){
	long long m, x, y, w;
	cin >> V >> m;
	vector<vector<long long>> graph(V);
	for(long long i = 0; i < V; i++){
		for(long long j = 0; j < V; j++){
			if(i == j){
				graph[i].push_back(0);
			}
			else{
				graph[i].push_back(INF);
			}
		}
	}
	for(long long i = 0; i < m; i++){
		cin >> x >> y >> w;
		graph[x-1][y-1] = w;
	}
	cin >> x;
	floydWarshall(graph, x-1);
	return 0; 
}