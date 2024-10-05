#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#include <ctype.h>
#include <iostream>
#include <vector>
using namespace std;
void jiaohuan_houtui(int *a,int si,int i,int n){
    //int s2 = si-1;//要换的那一位
    //si--;
    if(si==a[i]){
        return;
    }
    int tmp = a[si];
    a[si] = a[i];
    for(int k = i-1; k > si; k--){
        a[k+1] = a[k];
    }
    a[si+1] = tmp;
    //return a;
}
void read(int &x)
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    //printf("%d",x);
}
int main(){
    int n,kth;
    read(n);
    read(kth);
    const int k = n+1;
    int a[k];
    // const int n = 6;
    // int a[n] = {1,2,3,4,5,6};
    // jiaohuan_houtui(a,1,3,6);

    int sw[k];
    for(int i = 1;i<n+1;i++){
        int num;
        read(num);
        sw[i] = num;
    }
    for(int i = 1;i<n+1;i++){
        a[i] = i;
    }
    for(int i = 2; i < n+1; ++i){
        jiaohuan_houtui(a,sw[i],i,k);
    }
    // for(int i = 1; i < n+1; ++i){
    //     cout<<a[i]<<endl;
    // }
    cout<<a[kth]<<endl;
}