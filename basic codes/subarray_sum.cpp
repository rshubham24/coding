/*Given an array of n positive integers, your task is to count the number of subarrays having sum x.*/

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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, t, j = 0, k = 0, c = 0, l = 0;
	cin >> n >> t;
	v a;
	for(int i = 0; i < n; i++){
		cin >> x;
		a.pb(x);
	}
	while(j < n){
		if(l < t){
			if(k >= n){
				break;
			}
			l += a[k];
			k++;
		}
		else if(l > t){
			l -= a[j];
			j++;
		}
		else{
			l -= a[j];
			l += a[k];
			j++;
			k++;
		}
		if(l == t){
			c++;
		}
	}
	cout << c;
	return 0;
}