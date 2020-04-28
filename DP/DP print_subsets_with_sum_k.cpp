#include <bits/stdc++.h>

using namespace std;

int k[5][11];

void display(vector<int> p){
	for(int x : p){
		cout << x << " ";
	}
	cout << endl;
}

void print_subset(int a[], int i, int sum, vector<int> p){
	if(i == 0 && sum != 0 && k[0][sum] == 1){
		p.push_back(a[0]);
		display(p);
		return ;
	}
	if(i == 0 && sum == 0){
		display(p);
		return ;
	}
	if(k[i-1][sum] == 1){
		vector<int> b = p;
		print_subset(a, i-1, sum, b); 
	}
	if(sum >= a[i] && k[i-1][sum-a[i]] == 1){
		p.push_back(a[i]);
		print_subset(a, i-1, sum - a[i], p);
	}
}

void subset_sum(int a[], int sum, int n){
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
	if(!subset[n][sum]){
		return;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= sum; j++){
			if(subset[i+1][j]){
				k[i][j] = 1;
			}
			else{
				k[i][j] = 0;
			}
		}
	}
	vector<int> p;
	print_subset(a, n-1, sum, p);
	return ;
}

int main(){
	int a[5] = {1,2,3,4,5};
	int sum = 10;
	subset_sum(a, sum, 5);
    return 0;
}