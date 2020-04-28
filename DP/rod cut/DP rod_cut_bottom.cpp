#include <bits/stdc++.h>

using namespace std;

void bottom_rod_cut(int a[], int n, int r[]){
	int q;
	for(int j = 1; j <= n; j++){
		q = INT_MIN;
		for(int i = 1; i <= j; i++){
			q = max(q, a[i] + r[j-i]);
		}
		r[j] = q;
	}
	return;
}

int main(){
	int a[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int r[11];
	r[0] = 0;
	bottom_rod_cut(a, 10, r);
	for(int x : r){
		cout << x << " ";
	}
	return 0;
}

//T(n) = n^2;