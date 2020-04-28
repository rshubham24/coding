#include <bits/stdc++.h>

using namespace std;

long long p = 1000000007;

void initialize(long long f[]){
	for(int i = 0; i < 15; i++){
		f[i] = 1;
		for(int j = 0; j < i; j++){
			f[i] = ((f[i]%p)*263)%p;
		}
	}
}

long long hashing(string s, long long f[], long long m){
	long long k = 0;
	for(int i = 0; i < s.size(); i++){
		k = (k + (((int)s[i])*f[i])%p)%p;
	}
	return k%m;
}

int main(){
	long long f[14], m, w, i, e;
	initialize(f);
	cin >> m >> w;
	string s, c;
	vector<vector<string>> b(m);
	vector<string>::iterator it;
	unordered_map<string, long long> d;
	for(i = 0; i < w; i++){
		cin >> s;
		if(s == "add"){
			cin >> c;
			if(d.find(c) != d.end()){
			    continue;
			}
			else{
			    d.insert(make_pair(c, i));
		    	e = hashing(c, f, m);
			    b[e].push_back(c);   
			}
		}
		else if(s == "find"){
			cin >> c;
			if(d.find(c) != d.end()){
				cout << "yes" << endl;
			}
			else{
				cout << "no" << endl;
			}
		}
		else if(s == "check"){
			cin >> e;
			for(int j = b[e].size() - 1; j >= 0; j--){
				cout << b[e][j] << " ";
			}
			cout << endl;
		}
		else if(s == "del"){
			cin >> c;
			e = hashing(c, f, m);
			d.erase(c);
			it = b[e].begin();
			while(it != b[e].end()){
			    if((*it) == c){
			        b[e].erase(it);
			        break;
			    }
			    else{
			        it++;
			    }
			}
		}
	}
	return 0;
}