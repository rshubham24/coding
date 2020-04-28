#include <bits/stdc++.h>

using namespace std;

bool bipartite(vector<vector<int>> &a, int n, int v){
	vector<bool> vis(n, false);
	int bi[n];
	queue<int> q;
	q.push(v);
	bi[v] = 0;
	vis[v] = true;
	while(!q.empty()){
		int k = q.front();
		q.pop();
		for(int i = 0; i < a[k].size(); i++){
			if(!vis[a[k][i]]){
				q.push(a[k][i]);
				if(bi[k] == 0){
					bi[a[k][i]] = 1;
				}
				else{
					bi[a[k][i]] = 0;
				}
				vis[a[k][i]] = true;
			}
			else{
				if(bi[k] == bi[a[k][i]]){
					return false;
				}
			}
		}
	}
	return true;
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
	if(bipartite(a, n, 0)){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}