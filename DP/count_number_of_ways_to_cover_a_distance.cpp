// Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps.

// Recursive

#include <bits/stdc++.h>

using namespace std;

int dis(int n){
	if(n < 0){
		return 0;
	}
	if(n == 0){
		return 1;
	}
	return dis(n-1) + dis(n-2) + dis(n-3);
}

int main(){
	int n;
	cin >> n;
	cout << dis(n);
	return 0;
}

// DP

#include < bits/stdc++.h>

using namespace std;

int dis(int n, vector<int> &dp){
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	if(n == 1 || n == 2 || n == 3){
		return dp[n];
	}
	for(int i = 4; i <= n; i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	return dp[n];
}

int main(){
	int n;
	cin >> n;
	vector<int> dp(n+1, -1);
	dis(n, dp);
	return 0;
}