#include <bits/stdc++.h>

//using namespace std::chrono;
using namespace std;

long long mod = 1000000007;

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
#define vvl vector<vl>
#define vvp vector<vp>

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n;
	cin >> m;
	v a(m);
	for(int i = 0; i < m; i++){
		cin >> a[i];
	}
	cin >> n;
	int dp[m+1][n+1];
	for(int i = 0; i <= m; i++){
		dp[i][0] = 0;
	}
	for(int i = 1; i <= n; i++){
		dp[0][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(a[i-1] <= j && (dp[i][j-a[i-1]] != 0 || j-a[i-1] == 0)){
				if(dp[i-1][j] != 0){
					dp[i][j] = min(dp[i][j-a[i-1]] + 1, dp[i-1][j]);
				}
				else{
					dp[i][j] = dp[i][j-a[i-1]] + 1;
				} 
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	if(dp[m][n] == 0){
		cout << -1;
	}
	else{
		cout << dp[m][n];
	}
	return 0;
}