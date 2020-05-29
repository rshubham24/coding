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

ll subarray(vl &b, ll t){
	ll curr_sum = 0, ans = 0;
	map<int, int> a;
	for(int i = 0; i < b.size(); i++){
		curr_sum += b[i];
		if(curr_sum == t){
			ans++;
		}
		if(a.find(curr_sum - t) != a.end()){
			ans += a[curr_sum - t];
		}
		a[curr_sum]++;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, x, t; 
	cin >> n >> t;
	vl a;
	for(int i = 0; i < n; i++){
		cin >> x;
		a.pb(x);
	}
	cout << subarray(a, t);
	return 0;
}