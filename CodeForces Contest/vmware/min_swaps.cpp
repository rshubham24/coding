#include <bits/stdc++.h>

//using namespace std::chrono;
using namespace std;

long long mod = 1000000007;

typedef long long ll;
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

int minSwaps(v &a, int n){ 
    vp b(n); 
    rep(i, n){ 
        b[i].f = a[i]; 
        a[i].s = i; 
    } 
    sort(b.begin(), b.end(), greater<>());  
    vb vis(n, false);
    int ans = 0; 
    rep(i, n){ 
        if(vis[i] || b[i].s == i){ 
            continue;
        }
		int cycle_size = 0; 
        int j = i;
        while(!vis[j]){ 
            vis[j] = 1;
    	    j = b[j].s; 
            cycle_size++; 
        }
	    if (cycle_size > 0){ 
            ans += (cycle_size - 1); 
        }
    }  
    return ans; 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	v a(n);
	rep(i, n){
		cin >> a[i];
	}
   	cout << minSwaps(a, n); 
	return 0;
}	