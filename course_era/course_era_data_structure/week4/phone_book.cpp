#include <bits/stdc++.h>

using namespace std;

int main(){
	int l, x;
	string y, z;
	cin >> l;
	unordered_map<int, string> a;
	unordered_map<int, string>::iterator itr;
	for(int i = 0; i < l; i++){
		cin >> y;
		if(y == "add"){
			cin >> x >> z;
			itr = a.find(x);
			if(itr != a.end()){
				a.erase(x);
				a.insert(make_pair(x, z));	
			}
			else{
				a.insert(make_pair(x, z));
			}
		}
		else if(y == "del"){
			cin >> x;
			a.erase(x);
		}
		else{
			cin >> x;
			itr = a.find(x);
			if(itr != a.end()){
				cout << itr->second << endl;
			}
			else{
				cout << "not found" << endl;
			}
		}
	}
	return 0;
}