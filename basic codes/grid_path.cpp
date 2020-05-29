/*There are 88418 paths in a 7×7 grid from the upper-left square to the lower-left square. Each path corresponds to a 48-character description consisting of characters D (down), U (up), L (left) and R (right).

For example, the path

corresponds to the description DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.

You are given a description of a path which may also contain characters ? (any direction). Your task is to calculate the number of paths that match the description.
*/
include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std:: chrono;

typedef long long ll;
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define v vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define vs vector<string>

string k;
bool vis[7][7];
int w = 0, steps = 0;

void initialize(){
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			vis[i][j] = false;
		}
	}
}

void solve(int i, int j){
	bool t = vis[i][j] || (((i == 0 && vis[i+1][j]) || (i == 6 && vis[i-1][j])) && j > 0 && j < 6 && !vis[i][j+1] && !vis[i][j-1]) || (((j == 0 && vis[i][j+1]) || (j == 6 && vis[i][j-1])) && i > 0 && i < 6 && !vis[i+1][j] && !vis[i-1][j]) || (i > 0 && i < 6 && j > 0 && j < 6 && vis[i-1][j] && vis[i+1][j] && !vis[i][j+1] && !vis[i][j-1]) || (i > 0 && i < 6 && j > 0 && j < 6 && !vis[i-1][j] && !vis[i+1][j] && vis[i][j+1] && vis[i][j-1]);
	if(t){
		return;
	}
	if(i == 6 && j == 0){
		if(steps == 48){
			w++;
		}
		return;
	}
	if(steps == 48){
		return;
	}
	vis[i][j] = true;
	if(k[steps] == '?'){
		if(i < 6 && !vis[i+1][j]){
			steps++;
			solve(i+1, j);
			steps--;
		}
		if(i > 0 && !vis[i-1][j]){
			steps++;
			solve(i-1, j);
			steps--;
		}
		if(j < 6 && !vis[i][j+1]){
			steps++;
			solve(i, j+1);
			steps--;
		}
		if(j > 0 && !vis[i][j-1]){
			steps++;
			solve(i, j-1);
			steps--;
		}
	}
	else if(k[steps] == 'R'){
		if(j < 6 && !vis[i][j+1]){
			steps++;
			solve(i, j+1);
			steps--;
		}	
	}
	else if(k[steps] == 'L'){
		if(j > 0 && !vis[i][j-1]){
			steps++;
			solve(i, j-1);
			steps--;
		}
	}
	else if(k[steps] == 'U'){
		if(i > 0 && !vis[i-1][j]){
			steps++;
			solve(i-1, j);
			steps--;
		}
	}
	else{
		if(i < 6 && !vis[i+1][j]){
			steps++;
			solve(i+1, j);
			steps--;
		}
	}
	vis[i][j] = false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	//k = "??????R??????U??????????????????????????LD????D?";
	initialize();
	//auto start = high_resolution_clock::now(); 
	solve(0, 0);
	cout << w << endl;
	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(stop - start);
	//cout << duration.count() << endl; 
	return 0;
}