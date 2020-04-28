#include <bits/stdc++.h>

using namespace std;

int binary_search(int a[], int p, int q, int r){
	if(q >= p){
		int m = p + (q-p)/2;
		if(a[m] == r){
			return m;
		}
		if(a[m] > r){
			return binary_search(a, p, m-1, r);
		}
    	return binary_search(a, m+1, q, r);
	}
	return -1;
} 
int main(){
	int a[10] = {1,2,4,5,6,7,8,9,10,11};
	cout << binary_search(a, 0, 9, 8);
	return 0;
}