#include <bits/stdc++.h>

//using namespace std::chrono;
using namespace std;

typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define v vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<pair<int, int>>
#define vv vector<v>
#define vvl vector<vl>
#define vvp vector<vp>

string binary(string k){
	if(k.size() == 2){
		return k;
	}
	vector<string> str;
	for(int i = 0; i < k.size(); i++){
		int j = i;
		int count = 0;
		while(i < k.size()){
			if(k[i] == '1'){
				count++;
			}
			else{
				count--;
			}
			if(count == 0){
				break;
			}
			i++;
		}
		str.pb("1"+binary(k.substr(j+1, i-j-1))+"0");
	}
	sort(str.begin(), str.end(), greater<string>());
	string ans;
	for(auto i : str){
		ans += i;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string k;
	cin >> k;
	cout << binary(k);
	return 0;
}