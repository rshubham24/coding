// DP Solution

#include < bits/stdc++.h>

using namespace std;

bool dict_check(string s, string a[], int n){
	for(int i = 0; i < n; i++){
		if(a[i].compare(s) == 0){
			return true;
		}
	}
	return false;
}

bool pass_check(string s, string a[], int n){
	if(s.size() == 0){
		return true;
	}
	int d = s.size();
	vector<bool> dp(d+1, 0);
	for(int i = 1; i <= d; i++){
		if(dp[i] == false && dict_check(s.substr(0, i, n), a)){
			dp[i] = true;
		}
		if(dp[i] == true){
			if(i == d){
				return true;
			}
			for(int j = i+1; j <= d; j++){
				if(dp[j] == false && dict_check(s.substr(i, j-i, n), a)){
					dp[j] = true;
				}
				if(j == d && dp[j] == true){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	int n;
	cin >> n;
	string a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	string s;
	cin >> s;
	if(pass_check(s, a, n)){
		cout << "true";
	}
	else{
		cout << "false";
	}
}

// Optimized DP Solution

#include <bits/stdc++.h>

using namespace std;

bool dict_check(string s, string a[], int n){
	for(int i = 0; i < n; i++){
		if(a[i].compare(s) == 0){
			return true;
		}
	}
	return false;
}

bool pass_check(string s, string a[], int n){
	if(s.size() == 0){
		return true;
	}
	int d = s.size(), k, f;
	vector<bool> dp(d+1, 0);
	vector<int> index;
	index.push_back(-1);
	for(int i = 0; i < d; i++){
		k = index.size();
		f = 0;
		for(int j = k-1; j >= 0; j--){
			if(dict_check(s.substr(index[j] + 1, i - index[j]), a, n)){
				f = 1;
				break;
			}
		}
		if(f == 1){
			dp[i] = 1;
			index.push_back(i);
		}
	}
	return dp[d-1];
}

int main(){
	int n;
	cin >> n;
	string a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	string s;
	cin >> s;
	if(pass_check(s, a, n)){
		cout << "true";
	}
	else{
		cout << "false";
	}	
	return 0;
}

// Printing words in order which are present in the string 

#include <bits/stdc++.h>

using namespace std;

bool dict_check(string s, string a[], int n){
	for(int i = 0; i < n; i++){
		if(a[i].compare(s) == 0){
			return true;
		}
	}
	return false;
}

void print_word(string s, string a[], int d, int n, string result){
	for(int i = 1; i <= d; i++){
		string prefix = s.substr(0, i);
	    if(dict_check(prefix, a, n)){
		    if(i == d){
			    result += prefix;
			    cout << result << endl;
			    return;
		    }
		print_word(s.substr(i, d-i), a, d-i, n, result + prefix + " ");
	    }
	}
}

int main(){
	int n;
	cin >> n;
	string a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	string s;
	cin >> s;
	print_word(s, a, s.size(), n, "");
	return 0;
}