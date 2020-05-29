#include <bits/stdc++.h>

using namespace std;

int bs(vector<int> &dp, int l, int r, int a){
	while(r-l > 1){
		int m = l + (r-l)/2;
		if(dp[m] >= a){
			r = m;
		}
		else{
			l = m;
		}
	}
	return r;
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> dp(n, 0);
	dp[0] = a[0];
	int length = 1;
	for(int i = 1; i < n; i++){
		if(a[i] <= dp[0]){
			dp[0] = a[i];
		}
		else if(a[i] >= dp[length-1]){
			dp[length++] = a[i];
		}
		else{
			dp[bs(dp, -1, length-1, a[i])] = a[i];
		}
	}
	cout << length;
	return 0;
}