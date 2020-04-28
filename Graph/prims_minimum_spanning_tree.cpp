#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, int> PII;

long long prim(bool vis[], int edges, vector<vector<PII>> &a, int s){
	priority_queue<PII, vector<PII>, greater<PII>> b;
	b.push(make_pair(0, s));
	PII p;
	int y;
	long long mincost = 0;
	while(!b.empty()){
		p = b.top();
		b.pop();
		s = p.second;
		if(vis[s] == true){
			continue;
		}
		mincost += p.first;
		vis[s] = true;
		for(int i = 0; i < a[s].size(); i++){
			y = a[s][i].second;
			if(vis[y] == false){
				b.push(a[s][i]);
			}
		}
	}
	return mincost;
}

int main() {
	int nodes, edges, x, y;
	long long weight, mincost;
	cin >> nodes >> edges;
	vector<vector<PII>> a(nodes);
	bool vis[nodes];
	for(int i = 0; i < nodes; i++){
		vis[i] = false;
	}
	for(int i = 0; i < edges; i++){
		cin >> x >> y >> weight;
		a[x].push_back(make_pair(weight, y));
		a[y].push_back(make_pair(weight, x));
	}
	mincost = prim(vis, edges, a, 2);
	cout << mincost << endl;
	return 0;
}