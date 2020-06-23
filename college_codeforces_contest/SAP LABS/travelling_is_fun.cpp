#include <bits/stdc++.h>
 
using namespace std;
//using namespace std::chrono;
 
int mod = 1000000007;
 
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define v vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<p>
#define vpp vector<pair<int, p>>
#define vv vector<v>
#define vpl vector<pair<long long, long long>>
#define vvl vector<vl>
#define vvp vector<vp>
#define vvb vector<vb>

vv a(200001);
vb vis(200001, false);
v comp(200001);

void dfs(int b, int y){
	if(vis[b]){
		return;
	}
	vis[b] = true;
	comp[b] = y;
	for(int i = 0; i < a[b].size(); i++){
		if(!vis[a[b][i]]){
			dfs(a[b][i], y);
		}
	}
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, g, q, x, y = 1;
	cin >> n >> g >> q;
	for(int i = g+1; i <= n/2; i++){
		if(a[i].empty()){
			for(int j = 2*i; j <= n; j += i){
				a[i].pb(j);
				a[j].pb(i);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i, y);
			y++;
		}
	}
	v d(q);
	for(int i = 0; i < q; i++){
		cin >> d[i];
	}
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> x;
		if(comp[x] == comp[d[i]]){
			cout << 1;
		}
		else{
			cout << 0;
		}
		cout << endl;
	}
	return 0;
}