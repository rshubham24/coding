#include <bits/stdc++.h>

using namespace std;

void swap(int *i, int *j){
	int t = *i;
	*i = *j;
	*j = t;
}

int main(){
	int a[10] = {4,1,8,5,7,20,9,2,3,0};
	bool swapped;
	for(int i = 0; i < 10; i++){
		swapped = false;
		for(int j = 1; j < 10; j++){
			if(a[j] < a[j-1]){
				swap(&a[j], &a[j-1]);
				swapped = true;
			}
		}
		if(swapped == false){
			break;
		}
	}
	for(int i = 0; i < 10; i++){
		cout << a[i] << " ";
	}
	return 0;
}

// T(n) = n^(2);