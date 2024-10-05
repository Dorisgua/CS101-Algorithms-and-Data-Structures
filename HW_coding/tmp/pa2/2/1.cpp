#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#include <ctype.h>
#include <iostream>
#include <algorithm>
using namespace std;
void read(int &x)
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    //printf("%d",x);
}
int main(){
    int n,q;
    read(n);
    read(q);
    const int n_const=n;
    //int val_array[n_const+1];
    int min_point=100;
    int min_point_index=100;
    for(int i=1;i<=n;i++){
        int val; 
        read(val);
        //val_array[i]=val;
        if(min_point>val){
            min_point_index=i;
        }
    }
    int bingchaji[n_const+1];
    for(int i=1;i<n;i++){
        int index1,index2; 
        read(index1);
        read(index2);
    }

}