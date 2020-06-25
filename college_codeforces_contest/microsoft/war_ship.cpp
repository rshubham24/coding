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

int n;

int rec(int a, int m, int j){
	if(j == n){
		return 1;
	}
	int l = ((a*a)+1)%m;
	int ans = 0;
	rep(i, l){
		ans += rec(i, m, j + 1);
	}
	return ans+1;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> n >> m;
    cout << rec(2, m, 1)%m << endl;
	return 0;
}	