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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(6);
    cout << fixed;
    int n, m;
    cin >> n >> m;
    vector<pair<long double, long double>> a(m);
    rep(i, m){
    	cin >> a[i].f >> a[i].s;
    }
    long double ans = 0;
    repa(i, 0, m-2){
    	repa(j, i+1, m-1){
    		long double dis = (a[i].f-a[j].f)*(a[i].f-a[j].f) + (a[i].s-a[j].s)*(a[i].s-a[j].s);
    		long double dis1 = sqrtl(dis);
    		ans = max(dis1/n, ans);
    	}
    }
    cout << ans;
	return 0;
}	