#include <bits/stdc++.h>

//using namespace std::chrono;
using namespace std;

long long mod = 1000000007;

typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define v vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<p>
#define vpp vector<pair<int, p>>
#define vv vector<v>
#define vvb vector<vb>
#define vvl vector<vl>
#define vvp vector<vp>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repa(i, a, n) for(int i = a; i <= (n); ++i)
#define repd(i, n) for(int i = n; i >= 0; --i)

string ss(string k){
	int n = k.size();
    string rev = k;
    reverse(rev.begin(), rev.end());
    rep(i, n){
    	if(k.substr(0, n-i) == rev.substr(i)){
        	return rev.substr(0, i) + k;
    	}
    }
    return "";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string k;
	cin >> k;
	cout << ss(k);
	return 0;
}	