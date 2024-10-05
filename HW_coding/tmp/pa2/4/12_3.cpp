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
// bool cmp(int a,int b){
//     return a>b;//如果a>b为真则返回1
// }
int main(){
   int times;
    read(times);
    const int times_const = times;
    int nums[times_const+1];
    //int nums_index[100000];
    //int min_to_max[times_const+1];
    //int min_to_max_index[100000];
    int ans[times_const+1];
    //nums&&nums_index
    for(int i = 1;i<=times_const;i++){
        ans[i]=0;
        int num;
        read(num);
        nums[i]=num;
        //whether_consistent[i]=0;
        //nums_index[num]=i;
        //min_to_max[i]=num;
    }
    // int whether_consistent[times_const+1];
    // int stop_consistent;
    // for(int i = 1;i<times_const;i++){
    //     if(nums[i+1]==(nums[i]+1)||nums[i+1]==(nums[i]-1)){
    //         whether_consistent[i]=1
    //     }
    //     else{
            
    //     }
    // }
    int min=nums[1];
    int max=nums[1];
    int left=1;
    //int flag=0;
    int xiaoyudezhi=0;
    while(left<=times_const){
        min=nums[left];
        max=nums[left];
        int right=left;
        if(left!=1&&nums[left]<nums[left-1]){
            //flag=1;
            xiaoyudezhi=nums[left-1];
        }
        else{
            //flag=0;
            xiaoyudezhi=times_const;
        }
        while(right<=xiaoyudezhi){
            if(nums[right]<min){
                min=nums[right];
            }
            if(nums[right]>max){
                max=nums[right];
            }
            if((max-min)==(right-left)){
                ans[left]++;
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