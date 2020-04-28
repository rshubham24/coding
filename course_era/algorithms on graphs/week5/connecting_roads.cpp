#include <bits/stdc++.h>

using namespace std;

int n;

double dis(int x, int y, int w, int z){
	return sqrt((w-x)*(w-x) + (z-y)*(z-y));
}

int root(int id[], int x){
	while(id[x] != x){
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}

void unio(int id[], int x, int y){
	int p = root(id, x);
	int q = root(id, y);
	id[p] = id[q];
}

double kruskal(vector<pair<double, pair<int, int>>> &a){
	int id[n], x, y;
	for(int i = 0; i < n; i++){
		id[i] = i;
	}
	double cost = 0.0, e;
	for(int i = 0; i < a.size(); i++){
		e = a[i].first;
		x = a[i].second.first;
		y = a[i].second.second;
		if(root(id, x) != root(id, y)){
			cost += e;
			unio(id, x, y);
		}
	}
	return cost;
}

int main(){
	int x, y;
	cin >> n;
	vector<pair<int, int>> b;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		b.push_back(make_pair(x, y));
	}
	double e;
	vector<pair<double, pair<int, int>>> a;
	for(int i = 0; i < n - 1; i++){
		for(int j = i+1; j < n; j++){
		    e = 0.0;
			e += dis(b[i].first, b[i].second, b[j].first, b[j].second);
			a.push_back(make_pair(e, make_pair(i, j)));
		}
	}
	sort(a.begin(), a.end());
	cout << setprecision(10) << kruskal(a);
	return 0;
}