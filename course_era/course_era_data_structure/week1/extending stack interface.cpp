#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x, y;
	string s;
	cin >> n;
	stack<int> a;
	stack<int> b;
	b.push(-1);
	for(int i = 0; i < n; i++){
		cin >> s;
		if(s == "push"){
			cin >> x;
			a.push(x);
			y = b.top();
			if(y < x){
				b.push(x);
			}
			else{
				b.push(y);
			}
		}
		else if(s == "pop"){
			a.pop();
			b.pop();
		}
		else{
			cout << b.top() << endl;
		}
	}
	return 0;
}