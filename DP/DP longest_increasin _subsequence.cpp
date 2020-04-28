#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int dp[n];
	dp[0] = 1;
	int max1, k = 1;
	for(int i = 1; i < n; i++){
		max1 = INT_MIN;
		for(int j = i-1; j >= 0; j--){
			if(a[j] < a[i]){
				max1 = max(max1, dp[j]);
			}
		}
		if(max1 != INT_MIN){
			dp[i] = max1 + 1;
		}
		else{
			dp[i] = 1;
		}
		k = max(k, dp[i]);
	}
	cout << k;
    return 0;
}
