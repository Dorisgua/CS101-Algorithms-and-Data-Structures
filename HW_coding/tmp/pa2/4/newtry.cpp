#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include<queue>
sing namespace std;
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
    queue<int> max_index;
    queue<int> min_index;
    int max_index_of_all=1;
    int min_index_of_all=1;
    for(int i = 1;i<=times_const;i++){
        ans[i]=0;
        int num;
        read(num);
        nums[i]=num;
        if(nums[i]>nums[max_index_of_all]){
            max_index.push(i);
            max_index_of_all=i;
        }
        if(nums[i]<nums[min_index_of_all]){
            min_index.push(i);
            min_index_of_all=i;
        }
    }
    int left=1;
    while(left<=times_const){
        int right=left;
        while(right<=times_const){
            if((max-min)==(right-left)){
                ans[left]++;
            }
            right++;
        }
        left++;
    }
}