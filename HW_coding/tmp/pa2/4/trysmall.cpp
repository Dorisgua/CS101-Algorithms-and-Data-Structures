#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <iostream>
#include <algorithm>
using namespace std;
void read(int &x)//过了前四个点
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    //printf("%d",x);
}
int main(){
    int times;
    read(times);
    const int times_const = times;
    //const int maxn = 1000019,INF = 1e9;
    //int ch[times_const+1][times_const+1];
    int nums[times_const+1];
    for(int i = 1;i<=times_const;i++){
        ans[i]=0;
        int num;
        read(num);
        //ch[i][num]=num;
        nums[i]=num;
    }
    int flag_shangyige=0;
    int lianxu[times_const+1];
    for(int i = 1;i<times_const;i++){
        if(nums[i+1]==(nums[i]+1)||nums[i+1]==(nums[i]-1)){
            if(flag_shangyige==1&&(i+1)==times_const){
                //jieshu.push(i+1);
                lianxu[i+1]=nums[i+1];
            }
            //if(flag_shangyige==0){
                //kaishi.push(i);
                //lianxu[i]=nums[i];
            //}
            else{
                lianxu[i]=nums[i];
            }//flag=1;
            flag_shangyige=1;
        }
        else{
            if(flag_shangyige==1){
                //jieshu.push(i);
                lianxu[i]=nums[i];
            }
            flag_shangyige=0;
        }
    }
    int min=nums[1];
    int max=nums[1];
    for(int left=1;left<=times_const;left++){
        min=nums[left];
        max=nums[left];
        int right=left;
        int shangyige_index=times_const;
        if(right==1){
            shangyige_index=times_const;
        }
        else if(nums[right-1]>nums[right]){
            //shangyige_index=nums[right-1]+left;
            if(nums[right-1]+left<times_const){
                shangyige_index=nums[right-1]+left;
            }
        }
        else if(nums[right-1]<nums[right]){
            shangyige_index=times_const;
        }
        else{}
        //nums[right-1]是上一个
        while(right<=shangyige_index){
        //for(int right=left;right<=times_const;right++){
            
            if(nums[right]<min){
                min=nums[right];
            }
            if(nums[right]>max){
                max=nums[right];
            }
            if((max-min)==(right-left)){
                ans[left]++;
                //cout<<left;
            }
            right++;
        }
    } 

}