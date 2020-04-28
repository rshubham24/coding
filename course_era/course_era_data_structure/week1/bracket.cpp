#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int n = 0;
	stack<pair<char, int>> a;
	a.push(make_pair('*', 0));
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '[' || s[i] == '{' || s[i] == '('){
			a.push(make_pair(s[i], i+1));
			continue;
		}
		else if(s[i] == ']'){
			if(a.top().first == '['){
				a.pop();
			}
			else{
				cout << i+1;
				n = 1;
				break;
			}
		}
		else if(s[i] == '}'){
			if(a.top().first == '{'){
				a.pop();
			}
			else{
				cout << i+1;
				n = 1;
				break;
			}
		}
		else if(s[i] == ')'){
			if(a.top().first == '('){
				a.pop();
			}
			else{
				cout << i+1;
				n = 1;
				break;
			}
		}
	}
	if(n == 0){
		if(a.size() == 1){
			cout << "Success";
		}
		else{
			cout << a.top().second;
		}
	}
	return 0;
}