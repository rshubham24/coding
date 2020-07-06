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
    int m, n;
    cin >> m >> n;
    vv a(m, v(n));
    rep(i, m){
    	rep(j, n){
    		cin >> a[i][j];
    	}
    }
    int ans = 0;
    v c(n, 0);
    stack<int> b;
    rep(k, m){
        rep(j, n){
            if(a[k][j] == 0){
                c[j] = 0;
            }
            else{
                c[j]++;
            }
        }
        rep(i, n){
            while(!b.empty() && c[b.top()] > c[i]){
            	int area;
                int last = b.top();
                b.pop();
                    if(b.empty()){
                        area = c[last]*i;
                    }
                    else{
                        area = c[last]*(i-b.top()-1);
                    }
                    ans = max(area, ans);
                }
                b.push(i);
            }
            while(!b.empty()){
                int area;
                int last = b.top();
                b.pop();
                if(b.empty()){
                    area = c[last]*n;
                }
                else{
                    area = c[last]*(n-b.top()-1);
                }
                ans = max(area, ans);
            }
        }
        cout << ans;
	return 0;
}	