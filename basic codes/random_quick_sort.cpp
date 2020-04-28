#include <bits/stdc++.h>

using namespace std;

int partition(int a[], int p, int q){
	int x = a[q], e;
	int i = p - 1;
	for(int j = p; j <= q-1; j++){
		if(a[j] <= x){
			i++;
			e = a[j];
			a[j] = a[i];
			a[i] = e;
		}
	}
	e = a[q];
	a[q] = a[i+1];
	a[i+1] = e;
	return i+1;
}

int partition_r(int a[], int p, int q){
	srand(time(NULL));
	int random = p + rand()%(q - p + 1);
	int e = a[random];
	a[random] = a[q];
	a[q] = e;
	return partition(a, p, q);
}

void quick_sort(int a[], int p, int q){
	if(p <= q){
		int r = partition_r(a, p, q);
		quick_sort(a, p, r-1);
		quick_sort(a, r+1, q);
	}
}

int main(){
	int a[10] = {4,8,7,5,6,2,1,79,45,3};
	quick_sort(a, 0, 9);
	for(int j = 0; j < 10; j++){
		cout << a[j] << " ";
	}
	return 0;
}

// T(n) = nlogn (average time) : n^(2) (worst case). 