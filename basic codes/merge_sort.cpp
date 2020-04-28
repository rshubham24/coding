#include <bits/stdc++.h>

using namespace std;

void merge(int a[], int p, int q, int r){
	int l1[q-p+1], l2[r-q], k, j, i;
	for(i = 0; i <= q-p; i++){
		l1[i] = a[p+i];
	}
	for(i = 0; i < r-q; i++){
		l2[i] = a[q+1+i];
	}
	k = p, j = 0, i = 0;
	while(i < q-p+1 && j < r-q){ 
        if (l1[i] <= l2[j]){ 
            a[k] = l1[i]; 
            i++; 
        } 
        else{ 
            a[k] = l2[j]; 
            j++; 
        } 
        k++; 
    }
    while(i < q-p+1){ 
        a[k] = l1[i]; 
        i++; 
        k++; 
    } 
    while(j < r-q) { 
        a[k] = l2[j]; 
        j++; 
        k++; 
    } 
}

void merge_sort(int a[], int p, int q){
	if(p < q){
		int m = p + (q-p)/2;
		merge_sort(a, p, m);
		merge_sort(a, m+1, q);
		merge(a, p, m, q);
	}
}

int main(){
	int a[10] = {1,4,8,2,5,3,9,8,7,0};
	merge_sort(a, 0, 9);
	for(int i = 0; i < 10; i++){
		cout << a[i] << " ";
	}
	return 0;
}

// T(n) = n*log(n)