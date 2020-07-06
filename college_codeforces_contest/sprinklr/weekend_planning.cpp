#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll inf = 1e18;
ll mod = 1e9 + 7;
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
#define vvs vector<vs>
#define vvl vector<vl>
#define vvp vector<vp>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repa(i, a, n) for(int i = a; i <= (n); ++i)
#define repd(i, n) for(int i = n; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
int n;
vvp a;

void dijikstra(p state, int k){
	priority_queue<pair<ll, p>, vector<pair<ll, p>>, greater<pair<ll, p>>> q;
	q.push({0, state});
	vvl d(n, vl(k+1, inf));
	d[0][k] = 0;
	while(q.size()){
		pair<ll, p> t = q.top();
        q.pop();
        p u = t.s;
        if(t.f > d[u.f][u.s]){
            continue;
        }
        for(pair<ll, ll> it : a[u.f]){
            if(d[it.f][u.s] > d[u.f][u.s] + it.s){
                d[it.f][u.s] = d[u.f][u.s] + it.s;
                q.push({d[it.f][u.s], {it.f, u.s}});
            }
            if(u.s != 0 && d[it.f][u.s-1] > d[u.f][u.s]){
                d[it.f][u.s-1] = d[u.f][u.s];
                q.push({d[it.f][u.s-1], {it.f, u.s-1}});
            }
        }
    }
    rep(i, n){
        ll ans = inf;
        repa(j, 0, k){
            ans = min(ans, d[i][j]);
        }
        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
	int m, k;
    cin >> n >> m >> k;
 	a = vvp(n);
 	int x, y, w;
 	rep(i, m){
 		cin >> x >> y >> w;
 		x--;
 		y--;
 		a[x].pb(mp(y, w));
 		a[y].pb(mp(x, w));
 	}
 	dijikstra({0, k}, k);
    return 0;
}
