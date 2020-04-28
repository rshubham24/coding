#include <bits/stdc++.h>

using namespace std;

bool sum_subset(int a[],int k,int n){
    if(k < 0){
        return false;
    }
    if(k == 0){
        return true;
    }
    if(n == 0 && k != 0){
        return false;
    }
    bool is_taken = sum_subset(a, k - a[n-1], n-1);
    bool is_left = sum_subset(a, k, n-1);
    if(is_taken || is_left){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int a[5] = {9, 5, 3, 2, 4};
    int k = 80;
    if(sum_subset(a, k, 5)){
        cout << "Subset Present";
    }
    else{
        cout << "Subset not Present";
    }
    return 0;
}