#include <bits/stdc++.h>

using namespace std;

bool subset_sum(int a[], int sum, int n){
	bool subset[n+1][sum+1];
	for(int i = 0; i <= n; i++){
		subset[i][0] = true;
	}
	for(int i = 1; i <= sum; i++){
		subset[0][i] = false;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sum; j++){
			if(j < a[i-1]){
				subset[i][j] = subset[i-1][j];
			}
			if(j >= a[i-1]){
				subset[i][j] = subset[i-1][j] || subset[i-1][j - a[i-1]];
			}
		}
	}
	return subset[n][sum];
}

int main(){
	int a[6] = {3, 34, 4, 12, 5, 2};
	int sum = 14;
	if(subset_sum(a, sum, 6)){
		cout << "true";
	}
	else{
		cout << "false";
	}
    return 0;
}