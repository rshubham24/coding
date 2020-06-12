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
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repa(i, a, n) for(int i = a; i <= (n); ++i)

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, l;
	cin >> n;
	vv a(n, v(n, 0));
	rep(i, n){
		rep(j, n){
			cin >> a[i][j];
		}
	}
	vector<vv> dp(n+1, vv(n+1, v(n+1, -1)));
    dp[1][1][1] = a[0][0];
	repa(i, 1, n){
		repa(j, 1, n){
			repa(k, 1, n){
				l = i + j - k;
				if(l > n || l < 1 || dp[i][j][k] >= 0){
					continue;
				}
				if(a[i-1][j-1] == -1 || a[k-1][l-1] == -1){
					continue;
				}
				int m = max(max(max(dp[i-1][j][k-1], dp[i-1][j][k]), dp[i][j-1][k]), dp[i][j-1][k-1]);
				if(m == -1){
					dp[i][j][k] = -1;
				}
				else{
					dp[i][j][k] = m + a[i-1][j-1];
					if(i != k){
						dp[i][j][k] += a[k-1][l-1];
					}
				}
			}
		}
	}
	cout << max(0, dp[n][n][n]);
	return 0;
}	