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
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, g;
	cin >> n >> m;
	int a[n][m], b[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		g = 0;
		for(int j = 0; j < m; j++){
			if(i == 0){
				b[i][j] = a[i][j] - g;
			}
			else{
				b[i][j] = a[i][j] - a[i-1][j] - g;
			}
			g += b[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}