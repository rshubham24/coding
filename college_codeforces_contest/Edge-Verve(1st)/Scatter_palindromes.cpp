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
	string k, l;
	ll count = 0, r;
	cin >> k;
	for(int i = 0; i < k.size(); i++){
		for(int j = 1; j <= k.size()-i; j++){
			l = k.substr(i, j);
			v a(26, 0);
			r = 0;
			count++;
			for(int m = 0; m < l.size(); m++){
				a[(int)l[m] - 'a']++;
			}
			for(int m = 0; m < 26; m++){
				if(a[m]%2 != 0){
					r++;
				}
				if(r > 1){
					break;
				}
			}
			if(r > 1){
				count--;
			}
		}
	}
	cout << count;
	return 0;
}