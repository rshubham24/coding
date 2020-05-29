/* You are given n cubes in a certain order, and your task is to build towers using them. Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.

You must process the cubes in the given order. You can always either place the cube on top of an existing tower, or begin a new tower. What is the minimum possible number of towers?
*/

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

ll maxe;

void solve(int key, vl &b, int l, int n){
	if(l == n){
		b[l] = key;
		if(l == b.size()-1){
			maxe = key;
		}
		return;
	}
	int m = (n-l)/2 + l;
	if(key >= b[m]){
		return solve(key, b, m+1, n);
	}
	else{
		return solve(key, b, l, m);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, x;
	cin >> n;
	vl a;
	for(ll i = 0; i < n ; i++){
		cin >> x;
		a.pb(x);
	}
	vl b;
	b.pb(a[0]);
	maxe = a[0];
	for(ll i = 1; i < n; i++){
		if(a[i] >= maxe){
			b.pb(a[i]);
			maxe = a[i];
		}
		else{
			solve(a[i], b, 0, b.size()-1);
		}
	}
	cout << b.size();
	return 0;
}