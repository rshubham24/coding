#include <bits/stdc++.h>

using namespace std;

int coin_change(int a[], int m, int n){
	if(n == 0){
		return 1;
	}
	if(n < 0){
		return 0;
	}
	if(m <= 0 && n >= 1){
		return 0;
	}
	return coin_change(a, m-1, n) + coin_change(a, m, n-a[m-1]);
}

int main(){
	int a[] = {2, 5, 3, 6};
	int e = coin_change(a, 4, 10);	
	cout << e;
	return 0;
}