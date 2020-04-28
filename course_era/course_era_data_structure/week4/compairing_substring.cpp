#include <bits/stdc++.h> 

using namespace std; 
  
int main(){
	int n;
	string s;
	cin >> s >> n;
	int a[n][3];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		if((s.compare(a[i][0], a[i][2], s, a[i][1], a[i][2])) == 0){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
    return 0;
}
 