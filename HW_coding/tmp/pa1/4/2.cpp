#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#include <ctype.h>
#include <iostream>
#include <vector>
using namespace std;
void read(int &x)
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    //printf("%d",x);
}
int main(){
    int ans= -1;
    int n,k;
    read(n);
    read(k);
    const int s = n;
    int a[s];
    int sw[s];
    for(int i = 1;i<n+1;i++){
        int num;
        read(num);
        sw[n-i+1] = num;
    }
    // for(int i = 1; i < n+1; ++i){
    //     cout<<sw[i]<<endl;
    // }
    for(int i = 1;i<n+1;i++){
        a[i] = i;
    }
    int unsorted_sequence = 0;
    for(int i = 1;i<n;i++){
        if(k==sw[i]){
            ans = n-unsorted_sequence;
            break;
        }
        else if(k>sw[i]){
            k = k-1;
            unsorted_sequence++;
        }
        else{//k<sw[i]
            unsorted_sequence++;
        }
    }
    cout<<ans;
}