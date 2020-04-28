#include <bits/stdc++.h>

using namespace std;

int rod_cut(int p[], int k, int r[]){
	if(r[k] >= 0){
		return r[k];
	}
	int q;
	if(k == 0){
		q = 0;
	}
	else{
		q = INT_MIN;
		for(int i = 1; i < k+1; i++){
			q = max(q, p[i] + rod_cut(p, k-i, r));
		}
	}
	r[k] = q;
	return q;
}

int main(){
	int n, k;
	cin >> n >> k;
	int r[n], b[n+1];
	for(int i = 0; i < 11; i++){
	 	r[i] = INT_MIN;
	}
	b[0] = 0;
	for(int i = 1; i < n+1; i++){
		cin >> b[i];
	}
	rod_cut(b, n, r);
	cout << r[k];
	return 0;
}