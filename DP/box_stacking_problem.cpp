#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair

int main(){
	int n, x, y, z;
	cin >> n;
	vector<pair<int, pair<int, pair<int, int>>>> a;
	for(int i = 0; i < n; i++){
		cin >> x >> y >> z;
		a.pb(mp(x*y, mp(z, mp(min(x, y), max(x, y)))));
		a.pb(mp(y*z, mp(x, mp(min(y, z), max(y, z)))));
		a.pb(mp(z*x, mp(y, mp(min(z, x), max(y, z)))));
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	n = 3*n;
	vector<int> dp(n);
	for(int i = 0; i < n; i++){
	    dp[i] = a[i].s.f;
	}
	for(int i = 1; i < n; i++){
	    for(int j = 0; j < i; j++){
	        if(a[i].s.s.f < a[j].s.s.f && a[i].s.s.s < a[j].s.s.s && dp[i] < dp[j] + a[i].s.f){
	            dp[i] = dp[j] + a[i].s.f;
	        }
	    }
	}
	cout << *max_element(dp.begin(), dp.end());
	return 0;
}