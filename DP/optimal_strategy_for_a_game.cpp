#include <bits/stdc++.h>

using namespace std;

int rec(vector<int> &a, int start, int end){
	if(start == end){
	    return a[start];
	}
    if(end == start + 1){
	    return max(a[start], a[end]);
	}
	int ans = 0;
	int l = rec(a, start+1, end-1);
	ans = max(a[start] + min(rec(a, start+2, end), l), a[end] + min(l, rec(a, start, end-2)));
    return ans;
}

int main(){
	int n, x;
	cin >> n;
	vector<int> a;
	for(int i = 0; i < n; i++){
		cin >> x;
		a.push_back(x);
	}
	cout << rec(a, 0, n-1);
	return 0;
}
