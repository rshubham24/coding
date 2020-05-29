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

int rectangle(vv &dp, int m, int n){
	if(n == m){
		return 1;
	}
	if(dp[m][n] != -1){
		return dp[m][n];
	}
	int d = INT_MAX, e = INT_MAX;
	for(int i = 1; i <= m/2; i++){
		d = min(rectangle(dp, i, n) + rectangle(dp, m-i, n), d);
	}
	for(int i = 1; i <= n/2; i++){
		e = min(rectangle(dp, m, i) + rectangle(dp, m, n-i), e);	
	}
	dp[m][n] = min(d, e);
	return dp[m][n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> m >> n;
	vv dp(m+1);
	for(int i = 0; i < m+1; i ++){
		for(int j = 0; j < n+1; j++){
			dp[i].pb(-1);
		}
	}
	cout << rectangle(dp, m, n) - 1;
	return 0;
}