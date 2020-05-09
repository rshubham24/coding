#include <bits/stdc++.h>

using namespace std;

void max_heapify(int a[], int i, int n){
    int k = pow(2,(floor(log2(i)))+1) + 2*(i - pow(2,floor(log2(i))));
    int l = k, largest;
    int r = k+1;
    if(l <= n && a[l-1] > a[i-1]){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r <= n && a[r-1] > a[largest-1]){
        largest = r;
    }
    if(largest != i){
        int d = a[largest-1];
        a[largest-1] = a[i-1];
        a[i-1] = d;
        max_heapify(a, largest, n);
    }
}

void build_max_heap(int a[], int n){
    for(int i = n/2; i >= 1; i--){
        max_heapify(a, i, n);
    }
}

void heap_sort(int a[], int n){
    for(int i = n; i >=2; i--){
        build_max_heap(a, i);
        int d = a[0];
        a[0] = a[i-1];
        a[i-1] = d;
    }
}

int main(){
    int a[10] = {4,5,8,7,6,9,11,2,84,44};
    heap_sort(a, 10);
    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
    return 0;
}

//T(n) = n*log(n).
//Better time then merge sort.