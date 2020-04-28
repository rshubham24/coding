#include <bits/stdc++.h>

using namespace std;

int max, i, cuts;

void rope(string s, int length, int c, int n){
	if(i == n){
		return;
	}
	if(c == 0){
		max = 0;
		i = 0;
		c = 1;
		cuts = 0;
	}
	if(s[i] == '0'){
		return;
	}
	if(s[i] == '1'){
		length++;
		cut++;
		i++;
		if(length > max){
			max = length;
			cuts = cut;
		}
		rope(s, length, c);
		rope(s, length, c);
		return;
	}

}

int main(){
	for(int i = 0; i < 10; i++){
		int n;
		cin >> n;
		string s;
		cin >> s;
		rope(s, 0, 0, n);
		cout << cuts << endl;
	}
	return 0;
}