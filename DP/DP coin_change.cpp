#include <bits/stdc++.h>

using namespace std;

int main(){
	int a[4] = {2, 3, 5, 6};
	int r[11][4];
	for(int i = 0; i < 4; i++){
		r[0][i] = 1;
	}
	int x, y;
	for(int i = 1; i < 11; i++){
		for(int j = 0; j < 4; j++){
			if((i-a[j]) >= 0){
				x = r[i-a[j]][j];
			}
			else{
				x = 0;
			}
			if(j >= 1){
				y = r[i][j-1];
			}
			else{
				y = 0;
			}
			r[i][j] = x + y;
		}
	}
	cout << r[10][3];
	return 0;
}