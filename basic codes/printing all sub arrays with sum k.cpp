#include <bits/stdc++.h>

using namespace std;

vector<int> split(string &a, char c){
	vector<int> e;
	stringstream ss;
	ss << a;
	int x = 0;
	while(!ss.eof()){
		ss >> x;
		ss >> c;
		e.push_back(x);
	}
	return e;
}

void powerset(int a[],int n, int k){
	vector<string> r;
	for(int i = 0; i < pow(2, n); i++){
		string subset = "";
		for(int j = 0; j < n; j++){
			if((i & (1 << j)) != 0){
				subset += to_string(a[j]) + '*';
			}
		}
		if(find(r.begin(), r.end(), subset) == r.end()){
			r.push_back(subset);
		}
	}
	for(string a : r){
		vector<int>	b = split(a, '*');
		int count = 0;
		for(int i = 0; i < b.size()-1; i++){
			count += b[i];
		}
		if(count == k){
			for(int i = 0; i < b.size()-1; i++){
				cout << b[i] << " ";
			}
			cout << endl;
		}
	}
}

int main(){
	int n, k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	powerset(a, n, k);
	return 0;
}