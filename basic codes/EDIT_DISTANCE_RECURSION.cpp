#include <bits/stdc++.h>

using namespace std;

int min1(int a, int b, int c){
	return min(min(a, b), c);
}

int edit_distance(string s, string r, int m, int n){
	if(m == 0){
		return n;
	}
	if(n == 0){
		return m;
	}
	if(s[m-1] == r[n-1]){
		return edit_distance(s, r, m-1, n-1);
	}
	else{
		return 1 + min1(edit_distance(s, r, m, n-1), edit_distance(s, r, m-1, n), edit_distance(s, r, m-1, n-1));
	}
}

int main(){
	int t;
	cin >> t;
	for(int j = 0; j < t; j++){
		string s, r;
		cin >> s;
		cin >> r;
		int q = s.size(), p = r.size();
		cout << edit_distance(s, r, q, p) << endl; 
	}
    return 0;
}
