#include <bits/stdc++.h>

using namespace std;

int n, r;

void component(vector<vector<int>> &l, vector<bool> &vis, int src){
    vis[src] = true;
    for(int i = 0; i < l[src].size(); i++){
        if(!vis[l[src][i]]){
            component(l, vis, l[src][i]);
        }
    }
}

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
	int id[n], x, y, z;
	for(int i = 0; i < n; i++){
		id[i] = i;
	}
	vector<vector<int>> l(n);
	double cost = 0.0, e;
	for(int i = 0; i < a.size(); i++){
		e = a[i].first;
		x = a[i].second.first;
		y = a[i].second.second;
		if(root(id, x) != root(id, y)){
		    if(z == r){
		        return e;
		    }
			l[x].push_back(y);
			l[y].push_back(x);
			unio(id, x, y);
		}
		vector<bool> vis(n, false);
		z = 0;
		for(int j = 0; j < n; j++){
		    if(!vis[j]){
		        component(l, vis, j);
		        z++;
		    }
		}
	}
	return e;
}

int main(){
	int x, y;
	cin >> n;
	vector<pair<int, int>> b;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		b.push_back(make_pair(x, y));
	}
	cin >> r;
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
	cout << setprecision(10) << kruskal(a) << endl;
	return 0;
}   