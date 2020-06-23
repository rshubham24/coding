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

int n;

void color(vv &a){
	int dp[n][3];
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];
	for(int i = 1; i < n; i++){
		dp[i][0] = min(a[i][0]+dp[i-1][1], a[i][0]+dp[i-1][2]);
		dp[i][1] = min(a[i][1]+dp[i-1][0], a[i][1]+dp[i-1][2]);
		dp[i][2] = min(a[i][2]+dp[i-1][1], a[i][2]+dp[i-1][0]);
	}
	cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, y, z;
	cin >> n;
	vv a(n);
	for(int i = 0; i < n; i++){
		cin >> x >> y >> z;
		a[i].pb(x);
		a[i].pb(y);
		a[i].pb(z);
	}
	color(a);
	return 0;
}