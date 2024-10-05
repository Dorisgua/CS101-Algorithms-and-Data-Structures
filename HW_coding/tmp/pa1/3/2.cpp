#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#include <ctype.h>
#include <iostream>
using namespace std;
void read(int &x)
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    //printf("%d",x);
}
int main(){
    int n,k;
    read(n);
    read(k);
    if(k<=2){
        for(int i = 1;i<=n;i++){
            int num;
            read(num);
            cout<<num<<" ";
        }
        cout<<endl;
        return 0;
    }
    const int s1 = n+1;
    int a[s1];
    int index1 = 1;
    int index2 = 2;
    int num1,num2;
    read(num1);
    a[1] = num1;
    read(num2);
    a[2] = num2;

    for(int i = 3;i<=n;i++){
        int num;
        read(num);
        int flag = 0;
        cout<<"index1:"<<index1<<endl;
        if(index1+1<=index2&&a[index2]==a[index2-1]&&a[index2]==num){
            flag = 1;
        }
        if(index2-index1+1<k){
            if(flag==1){
                index2 = index2-2;
            }
            else{
                index2++;
                a[index2] = num;
            }
        }
        else{//index2-index1+1==k
            if(flag==1){
                index2 = index2-2;
            }
            else{
                index2++;
                a[index2] = num;
                index1++;
            }
        }
        for(int i = 1;i<=index2;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    for(int i = 1;i<=index2;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}