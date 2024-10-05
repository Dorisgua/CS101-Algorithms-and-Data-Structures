#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
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
    int nums[times_const+1];
    int ans[times_const+1];
    int flag[times_const+1];//判断是否连续
    for(int i = 1;i<=times_const;i++){
        ans[i]=0;
        int num;
        read(num);
        nums[i]=num;
    }
    int j=1;
    while(j<times_const){
       if(nums[j+1]==nums[j]+1){
            flag[j]=1;
        }
        else{
            flag[j]=0;
        }
        j++;
    }
    
    int min=nums[1];
    int max=nums[1];
    int left=1;
    int flag_whether_be=0;
    //for(int left=1;left<=times_const;left++){
    while(left<=times_const){
        min=nums[left];
        max=nums[left];
        int right=left;
        //for(int right=left;right<=times_const;right++){
        while(right<=times_const){
            if(flag_whether_be==1){
                while((flag[right])==1){
                    ans[left]++;
                    max++;
                    right++;
                    //cout<<right<<endl;
                }
            }
            if(nums[right]<min){
                min=nums[right];
            }
            if(nums[right]>max){
                max=nums[right];
            }
            if((max-min)==(right-left)){
                ans[left]++;
                flag_whether_be=1;
            }
            else{
                flag_whether_be=0;
            }
            right++;
        }
        left++;
    } 
    for(int i = 1; i < times_const+1; i++){
        cout<<ans[i]<<" ";
    } 
    cout<<endl;
}