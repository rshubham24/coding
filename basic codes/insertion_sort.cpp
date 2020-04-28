#include <bits/stdc++.h>

using namespace std;

int main(){
	int a[10] = {4,1,8,3,6,7,9,2,5,0}, i, j, key;
	for(i = 1; i < 10; i++){
		key = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > key){
			a[j+1] = a[j];
			j = j - 1;
		}
		a[j+1] = key;
	}
	for(i = 0; i < 10; i++){
		cout << a[i] << " ";
	}
	return 0;
}

//T(n) = n^(2);