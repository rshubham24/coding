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
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, curr = 0, counte = 0;
	cin >> n;
	v a, b;
	vp c;
	for(int i = 0; i < n; i++){
		cin >> x;
		a.pb(x);
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		b.pb(x+a[i]);
	}
	for(int i = 0; i < n; i++){
		c.pb(mp(b[i], a[i]));
	}
	sort(c.begin(), c.end());
	for(int i = 0; i < n; i++){
		if(c[i].s >= curr){
			counte++;
			curr = c[i].f;
		}
	}
	cout << counte;
	return 0;
}