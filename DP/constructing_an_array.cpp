/*You know that an array has n integers between 1 and m, and the difference between two adjacent values is at most 1.

Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.*/

#include <bits/stdc++.h>

using namespace std;
//using namespace std::chrono;

int mod = 1000000007;

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
#define vv vector<vector<int>>

int main(){
 	int n, m;
  	cin >> n >> m;
  	v a(n);
  	for(int i = 0; i < n; i++){
  		cin >> a[i];	
  	} 
  	vv s(n, v(m + 1));
  	for(int j = 1; j <= m; j++){
    	if(a[0] && j == a[0] || !a[0]){
      		s[0][j] = 1;
      	}
    }
  	for(int i = 1; i < n; i++){
    	for(int j = 1; j <= m; j++){
      		if(a[i] && j == a[i] || !a[i]){
	        	for(int k = max(0, j - 1); k <= min(m, j + 1); k++){
    		      	(s[i][j] += s[i - 1][k]) %= mod;
	        	}
      		}
      	}
    }
  	int c = 0;
  	for(int i = 1; i <= m; i++){
    	(c += s[n - 1][i]) %= mod;
  	}
  	cout << c << "\n";
}