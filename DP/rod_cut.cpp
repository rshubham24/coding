#include <bits/stdc++.h>

using namespace std;

int rod_cut(vector<int> &a, int n){
	int dp[n+1], k;
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		k = -1;
		for(int j = 0; j < i; j++){
			k = max(k, a[j] + dp[i-j-1]);
		}
		dp[i] = k;
	}
	return dp[n];
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << rod_cut(a, n);
	return 0;
}