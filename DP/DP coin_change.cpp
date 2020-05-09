// Recursive

#include <bits/stdc++.h>

using namespace std;

int coin_change(vector<int> &a, int n, int k, int i, int sum){
	if(i == n){
		return 0;
	}
	int ans = 0;
	if(sum == k){
		return ans + 1;
	}
	else if(sum > k){
		return 0;
	}
	else{
		ans = coin_change(a, n, k, i, sum + a[i]) + coin_change(a, n, k, i+1, sum);
	}
	return ans;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << coin_change(a, n, k, 0, 0);
	return 0;
}

// DP

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> dp(k+1, 0);
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = a[i]; j <= k; j++){
			dp[j] += dp[j-a[i]];
		}
	}
	cout << dp[k];
	return 0;
}