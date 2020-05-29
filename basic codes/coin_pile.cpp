/*You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.
Your task is to efficiently find out if you can empty both the piles.*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define v vector<int>
#define vl vector<long>
#define vb vector<bool>

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t, x, y;
	cin >> t;
	while(t--){
		cin >> x >> y;
		if(x < y){
			swap(x, y);
		}
		if(x > 2*y){
			cout << "NO";
		}
		else{
			x = x%3;
			y = y%3;
			if(x < y){
				swap(x, y);
			}
			if((x == 2 && y == 1) || (x == y && y == 0)){
				cout << "YES";
			}
			else{
				cout << "NO";
			}
		}
		cout << endl;
	}
	return 0;
}