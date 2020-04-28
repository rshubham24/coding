#include <bits/stdc++.h>

using namespace std;

vector<pair<long long int, pair<int, int>>> a;

int root(int x, int id[]){
	while(id[x] != x){
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}

void unio(int x, int y, int id[]){
	int p = root(x, id);
	int q = root(y, id);
	id[p] = id[q];
}

int kruskal(int edges, int id[]){
	long long int mincost = 0;
	int x, y;
	for(int i = 0; i < edges; i++){
		x = a[i].second.first;
		y = a[i].second.second;
		long long int cost = a[i].first;
		if(root(x, id) != root(y, id)){
			mincost += cost;
			unio(x, y, id);
		}
	}
	return mincost;
}

int main(){
	int nodes, edges;
	cin >> nodes >> edges;
	int id[nodes];
	for(int i = 0; i < nodes; i++){
	    id[i] = i;
	}
	int x, y;
	long long int mincost, weight;
	for(int i = 0; i < edges; i++){
		cin >> weight >> x >> y;
		a.push_back(make_pair(weight, make_pair(x, y)));
	}
	sort(a.begin(), a.end());
	mincost = kruskal(edges, id);
	cout << mincost << endl;
	return 0;
}