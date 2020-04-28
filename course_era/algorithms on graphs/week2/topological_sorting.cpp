#include <bits/stdc++.h>

using namespace std;

void topological_sorting(vector<vector<int>> &a, int n){
	vector<int> t;
	vector<bool> vis(n, false);
	vector<int> index(n, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < a[i].size(); j++){
			index[a[i][j]]++;
		}
	}
	queue<int> q;
	for(int i = 0; i < n; i++){
		if(index[i] == 0){
			q.push(i);
			vis[i] = true;
		}
	}
	while(!q.empty()){
		int k = q.front();
		q.pop();
		t.push_back(k);
		for(int i = 0; i < a[k].size(); i++){
			index[a[k][i]]--;
			if(index[a[k][i]] == 0 && vis[a[k][i]] == false){
				q.push(a[k][i]);
				vis[a[k][i]] = true;
			}
		}
	}
	for(int i = 0; i < t.size(); i++){
	    cout << t[i] + 1<< " ";
	}
}

int main(){
	int n, m, x, y;
	cin >> n >> m;
	vector<vector<int>> a(n);
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		a[x-1].push_back(y-1);
	}
	topological_sorting(a, n);
	return 0;
}