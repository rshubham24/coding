// counting combinations of nqueen

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define v vector<int>
#define vb vector<bool>

int n, counte = 0;;
vb col(100, 0), diag1(100, 0), diag2(100, 0);

void queen(int k){
	if(k == n){
		counte++;
		return;
	}
	for(int i = 0; i < n; i++){
		if(col[i] || diag1[i+k] || diag2[i-k+n-1]){
			continue;
		}
		col[i] = diag1[i+k] = diag2[i-k+n-1] = 1;
		queen(k+1);
		col[i] = diag1[i+k] = diag2[i-k+n-1] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	queen(0);
	cout << counte;
	return 0;
}

// printing all combinations

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define v vector<int>
#define vb vector<bool>

int n;
vb col(100, 0), diag1(100, 0), diag2(100, 0);

void print(vector<vb> &b){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void queen(int k, vector<vb> &b){
	if(k == n){
		print(b);
		return;
	}
	for(int i = 0; i < n; i++){
		if(col[i] || diag1[i+k] || diag2[i-k+n-1]){
			continue;
		}
		col[i] = diag1[i+k] = diag2[i-k+n-1] = 1;
		b[k][i] = 1;
		queen(k+1, b);
		col[i] = diag1[i+k] = diag2[i-k+n-1] = 0;
		b[k][i] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<vb> b(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			b[i].push_back(0);
		}
	}
	queen(0, b);
	return 0;
} 