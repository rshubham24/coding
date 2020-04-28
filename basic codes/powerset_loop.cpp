#include <bits/stdc++.h>

using namespace std;

string powerset(string s, int n, string s1, int n1){
	vector<string> a;
	for(int i = 0; i < pow(2, n); i++){
		string subset = "";
		for(int j = 0; j < n; j++){
			if((i & (1 << j)) != 0){
				subset += s[j];
			}
		}
		if(find(a.begin(), a.end(), subset) == a.end()){
			a.push_back(subset);
		}
	}
	vector<string> b;
	for(int i = 0; i < pow(2, n1); i++){
		string subset = "";
		for(int j = 0; j < n1; j++){
			if((i & (1 << j)) != 0){
				subset += s1[j];
			}
		}
		if(find(b.begin(), b.end(), subset) == b.end()){
			b.push_back(subset);
		}
	}
	int max = INT_MIN, c = 0;
	string q, w;
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < b.size(); j++){
			if(a[i] == b[j]){
				q = a[i];
				c = q.size();
			}
			if(c > max){
				w = q;
			}
		}
	}
	return w;
	/*for(string str : a){
		cout << str << endl;
	}*/
}

int main(){
	string s = "ABCBDAB";
	string s1 = "BDCBAB";
	/*string s;
	getline(cin, s);*/
	string e = powerset(s, s.size(), s1, s1.size());
	cout << e;
	return 0;
}