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
#define vl vector<long long>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<pair<int, int>>
#define vv vector<v>
#define vpl vector<pair<long long, long long>>
#define vvl vector<vl>
#define vvp vector<vp>
#define vvb vector<vb>

ll inf = 1e18;

void floyd_warshall(vvl &a, int n, int q)	{
	for(int k = 0; k < n; k++){ 
		for(int i = 0; i < n; i++){ 
			for(int j = i+1; j < n; j++){
				if(a[i][k] + a[k][j] < a[i][j]){
		           a[i][j] = a[j][i] = a[i][k] + a[k][j];
				}
			}
		}
	}
	int x, y;
	for(int i = 0; i < q; i++){
		cin >> x >> y;
		x--;
		y--;
		if(x == y){
			cout << 0 << endl;
		}
		else if(a[x][y] == inf){
			cout << -1 << endl;
		}
		else{
			cout << a[x][y] << endl;
		}
	}
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x, y, z, q;
	cin >> n >> m >> q;
	vvl a(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i].pb(inf);
		}
	}
	for(int i = 0; i < m; i++){
		cin >> x >> y >> z;
		x--;
		y--;
		if(a[x][y] > z){
			a[x][y] = z;
			a[y][x] = z;
		}
	}
	floyd_warshall(a, n, q);
	return 0;
}