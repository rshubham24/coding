#include <bits/stdc++.h>

using namespace std;

int matrix_multiplication(vector<int> &a, int n){
	int dp[n][n];
	for(int i = 1; i < n; i++){
		dp[i][i] = 0;
	}
	int j, q;
	for (int k = 2; k < n; k++){ 
        for (int i = 1; i < n - k + 1; i++) { 
            j = i + k - 1; 
            dp[i][j] = INT_MAX; 
            for (int l = i; l <= j - 1; l++){ 
                q = dp[i][l] + dp[l + 1][j] + a[i - 1] * a[l] * a[j]; 
                if(q < dp[i][j]){
                	dp[i][j] = q;
                }
            } 
        } 
    }
    return dp[1][n-1];
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << matrix_multiplication(a, n);
	return 0;
}
