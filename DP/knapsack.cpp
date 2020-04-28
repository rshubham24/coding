#include<bits/stdc++.h>

using namespace std;

int knapsack(int val[], int wei[], int n, int r){
	int knap[n+1][r+1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= r; j++){
			if(i == 0 || j == 0){
				knap[i][j] = 0;
			}
			else if(wei[i-1] <= j){
				knap[i][j] = max(val[i-1] + knap[i-1][j - wei[i-1]], knap[i-1][j]);
			}
			else{
				knap[i][j] = knap[i-1][j];
			}
		}
	}
	return knap[n][r];
} 
   
int main() {
	int value[3] = {60, 100, 120};
	int weight[3] = {10, 20, 30};
	cout << knapsack(value, weight, 3, 40);
    return 0;
} 
