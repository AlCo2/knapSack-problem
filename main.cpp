#include <iostream>

using namespace std;


int Max(int a, int b){
    return a > b ? a:b;
}

int knapSack(int w,int n,int wt[], int val[]){
    if(n==0 || w==0)
        return 0;
    if(wt[n-1]>w){
        return knapSack(w, n-1, wt, val);
    }else{
        return Max(val[n-1]+knapSack(w-wt[n-1],n-1,wt,val), knapSack(w,n-1,wt, val));
    }
}


int main(){
    int val[] = { 60, 100, 120,500};
    int wt[] = { 10, 20, 30, 20};
    int W = 40;
    int n = sizeof(val) / sizeof(val[0]);
    cout << "best: " << knapSack(W,n, wt, val);
    return 0;
}
