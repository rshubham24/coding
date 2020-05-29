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

ll min_max = -1222222222222222;

ll rec(vvl &dp, vl &a, int start, int end){
	if(dp[start][end] != min_max){
		return dp[start][end];
	}
	if(start == end){
	    return a[start];
	}
    if(end == start + 1){
	    return max(a[start], a[end]);
	}
	ll ans = 0, l , m, n;
	if(dp[start+1][end-1] != min_max){
		l = dp[start+1][end-1];
	}
	else{
		l = rec(dp, a, start+1, end-1);
	}
	if(dp[start+2][end] != min_max){
		m = dp[start+2][end];
	}
	else{
		m = rec(dp, a, start+2, end);
	}
	if(dp[start][end-2] != min_max){
		n = dp[start][end-2];
	}
	else{
		n = rec(dp, a, start, end-2);
	}
	ans = max(a[start] + min(m, l), a[end] + min(l, n));
	dp[start][end] = ans;
    return dp[start][end];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vl a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vvl dp(n+1);
	for(int i = 0; i < n+1; i++){
		for(int j = 0; j < n+1; j++){
			dp[i].pb(min_max);
		}
	}
	cout << rec(dp, a, 0, n-1);
	return 0;
}