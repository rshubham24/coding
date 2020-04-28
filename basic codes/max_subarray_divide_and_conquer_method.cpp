#include <bits/stdc++.h>

using namespace std;

int max(int a, int b, int c){
	return max(max(a, b), c);
}

int max_crossing(int a[], int b, int m, int c){
	int sum = 0;
	int lmin = INT_MIN;
	for(int i = m; i >= b; i--){
		sum = sum + a[i];
		if(sum > lmin){
			lmin = sum;
		}
	}
	sum = 0;
	int rmin = INT_MIN;
	for(int i = m+1; i <= c; i++){
		sum = sum + a[i];
		if(sum > rmin){
			rmin = sum;
		}
	}
	return lmin + rmin;
}

int max_subarray(int a[], int b, int c){
	if(b == c){
		return a[b];
	}
	int m = (b+c)/2;
	return max(max_subarray(a, b, m), max_subarray(a, m+1, c), max_crossing(a, b, m, c));
}

int main(){
	int a[10] = {1,-8,7,-9,-4,15,4,-8,23,1};
	int max = max_subarray(a, 0, 9);
	cout << max;
	return 0;
} 