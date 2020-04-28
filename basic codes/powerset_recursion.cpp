#include <bits/stdc++.h>

using namespace std;

void powerset(string s, int b, string sr){
	int n = s.size();
	if(b == n){
		return;
	}
	cout << sr << endl;
	for(int i = b + 1; i < n; i++){
		sr += s[i];
		powerset(s, i, sr);
		sr.erase(sr.size() - 1);
	}
	return;
}

int main(){
	string s, sr = "";
	getline(cin, s);
	powerset(s, -1, sr);
	return 0;
}