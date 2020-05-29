/* when we have two knights threatening each other, it actually forms either a 2×3 or 3×2 board. And for each of 2×3 and 3×2 boards, there are 2 ways of placing two knights so that they threaten each other. So, what we should do is to count how many 2×3 and 3×2 squares on n×n board. For general n, the answer is
2(n−1)(n−2) */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define v vector<int>
#define vb vector<bool>

ll knight(ll i){
	ll d = (i*i)*(i*i - 1);
	d = d/2;
	d = d - 4*(i-1)*(i-2);
	return d;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cout << knight(i) << endl;
	}
	return 0;
}