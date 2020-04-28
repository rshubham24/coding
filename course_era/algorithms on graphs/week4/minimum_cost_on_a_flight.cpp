#include <bits/stdc++.h>

using namespace std;

int min_dis(vector<vector<pair<int, int>>> &a, int n, vector<int> &disc, vector<bool> &vis){
	int min = INT_MAX, index = -1;
	for(int i = 0; i < n; i++){
		if(!vis[i] && disc[i] < min){
			min = disc[i];
			index = i;
		}
	}
	return index;
}

void cost(vector<vector<pair<int, int>>> &a, int n, vector<int> &disc,  int src, int des){
	vector<bool> vis(n, false);
	disc[src] = 0;
	int k;
	for(int i = 0; i < n-1; i++){
		k = min_dis(a, n, disc, vis);
		if(k == -1){
		    return;
		}
		if(k == des){
			return;
		}
		vis[k] = true;
		for(int j = 0; j < a[k].size(); j++){
			if(!vis[a[k][j].first] && disc[k] != INT_MAX && disc[k] + a[k][j].second < disc[a[k][j].first]){
				disc[a[k][j].first] = disc[k] + a[k][j].second; 
			}
		}
	}
}

int main(){
	int n, m, x, y, w;
	cin >> n >> m;
	vector<vector<pair<int, int>>> a(n);
	for(int i = 0; i < m; i++){
		cin >> x >> y >> w;
		a[x-1].push_back(make_pair(y-1, w));
	}
	cin >> x >> y;
	vector<int> disc(n, INT_MAX);
	cost(a, n, disc, x-1, y-1);
	if(disc[y-1] != INT_MAX){
		cout << disc[y-1];
	}
	else{
		cout << -1;
	}
	return 0;
}