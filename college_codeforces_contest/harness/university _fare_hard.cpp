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

int find(vpp &d, int i){
	for(int j = i-1; j >= 0; j--){
		if(d[j].f <= d[i].s.f){
			return j;
		}
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	v a(n), b(n), c(n);
	for(int  = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	vpp d;
	for(int i = 0; i < n; i++){
		d.pb(mp(a[i]+b[i], mp(a[i], c[i])));
	}
	sort(d.begin(), d.end());
	v dp(n);	
	int sum;
	dp[0] = d[0].s.s;
	for(int i = 1; i < n; i++){
		sum = d[i].s.s;
		l = find(d, i);
		if(l != -1){
			sum += dp[l];
		}
		dp[i] = max(dp[i-1], sum);
	}
	cout << dp[n-1];
	return 0;
}