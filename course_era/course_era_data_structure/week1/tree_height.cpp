#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, src, x;
	cin >> n;
	vector<vector<int>> a(n);
	for(int i = 0; i < n; i++){
		cin >> x;
		if(x == -1){
			src = i;
		}
		else{
			a[i].push_back(x);
			a[x].push_back(i);
		}
	}
	queue<int> b;
	vector<int> level(n, 1);
	vector<bool> vis(n, false);
	b.push(src);
	vis[src] = true;
	while(!b.empty()){
		x = b.front();
		b.pop();
		for(int i = 0; i < a[x].size(); i++){
			if(vis[a[x][i]] == false){
				level[a[x][i]] = level[x] + 1;
				b.push(a[x][i]);
				vis[a[x][i]] = true;
			}
		}
	}
	cout << *max_element(level.begin(), level.end());
	return 0;
}