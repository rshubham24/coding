#include <bits/stdc++.h>

using namespace std;

void biconnect(vector<vector<int>> &a, int low[], int disc[], vector<bool> &vis, vector<int> &parent, stack<pair<int, int>> &s, int vertex){
	static int time = 0;
	low[vertex] = disc[vertex] = ++time;
	int children = 0;
	vis[vertex] = true;
	for(int i = 0; i < a[vertex].size(); i++){
		if(vis[a[vertex][i]] == false){
			children++;
			parent[a[vertex][i]] = vertex;
			s.push(make_pair(vertex, a[vertex][i]));
			biconnect(a, low, disc, vis, parent, s, a[vertex][i]);
			low[vertex] = min(low[vertex], low[a[vertex][i]]);
			if(parent[vertex] == -1 && children > 1){
				while(s.top().first != vertex && s.top().second != a[vertex][i]){
					cout << s.top().first << "---" << s.top().second << "  ";
					s.pop();
				}
				cout << s.top().first << "---" << s.top().second << endl;
				s.pop();
			}
			if(parent[vertex] != -1 && low[a[vertex][i]] >= disc[vertex]){
				while(s.top().first != vertex && s.top().second != a[vertex][i]){
					cout << s.top().first << "---" << s.top().second << "  ";
					s.pop();
				}
				cout << s.top().first << "---" << s.top().second << endl;
				s.pop();
			}
		}
		else if(parent[vertex] != a[vertex][i]){
			low[vertex] = min(low[vertex], disc[a[vertex][i]]);
			if (disc[a[vertex][i]] < disc[vertex]) { 
                s.push(make_pair(vertex, a[vertex][i]));
            }
		}
	}
}

int main(){
	int n, m, x, y;
	cin >> n >> m;
	vector<vector<int>> a(n);
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	vector<bool> vis(n, false);
	vector<int> parent(n, -1);
	int low[n], disc[n];
	stack<pair<int, int>> s;
	biconnect(a, low, disc, vis, parent, s, 4);
	while(!s.empty()){
	    cout << s.top().first << "---" << s.top().second << "  ";
	    s.pop();
	}
	return 0;
}