#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mode = 1000000007;
#define f first
#define s second
#define ss string
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define pp pair<int, p>
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
#define repd(i, n) for(int i = n; i >= 0; --i)
#define all(x) (x).begin(), (x).end()

int bs(v &dp, int l, int r, int a){
	while(r-l > 1){
		int m = l + (r-l)/2;
		if(dp[m] >= a){
			r = m;
		}
		else{
			l = m;
		}
	}
	return r;
}

int lis(v &a, int n){
	v dp(n, 0);
	dp[0] = a[0];
	int length = 1;
	repa(i, 1, n-1){
		if(a[i] < dp[0]){
			dp[0] = a[i];
		}
		else if(a[i] > dp[length-1]){
			dp[length++] = a[i];
		}
		else{
			dp[bs(dp, -1, length-1, a[i])] = a[i];
		}
	}
	int g = n - length - 1;
	if(g < 0){
		return 0;
	}
	else{
		return g;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    v a(n);
    rep(i, n){
    	cin >> a[i];
    }
    cout << lis(a, n);
	return 0;
}