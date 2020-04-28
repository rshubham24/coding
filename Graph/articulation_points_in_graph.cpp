#include <bits/stdc++.h>

using namespace std;

void articulation(vector<vector<int>> &a, int disc[], int low[], int parent[], bool ap[], bool vis[], int vertex){
	static int time = 0;
	time++;
	vis[vertex] = true;
	low[vertex] = disc[vertex] = time;
	int children = 0;
	for(int i = 0; i < a[vertex].size(); i++){
		if(!vis[a[vertex][i]]){
			children++;
			parent[a[vertex][i]] = vertex;
			articulation(a, disc, low, parent, ap, vis, a[vertex][i]);
			low[vertex] = min(low[a[vertex][i]], low[vertex]);
			if (parent[vertex] == -1 && children > 1){
                ap[vertex] = true;  
           	}
            if (parent[vertex] != -1 && low[a[vertex][i]] >= disc[vertex]){ 
                ap[vertex] = true;
        	}
		}
		else if(a[vertex][i] != parent[vertex]){
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
		a[x-1].push_back(y-1);
		a[y-1].push_back(x-1);
	}
	int disc[n], low[n], parent[n];
	bool ap[n], vis[n];
	for(int i = 0; i < n; i++){
		parent[i] = -1;
		ap[i] = false;
		vis[i] = false;
	}
	articulation(a, disc, low, parent, ap, vis, 0);
	for(int i = 0; i < n; i++){
		if(ap[i] == true){
			cout << i+1 << " ";
		}
	}
	return 0;
}