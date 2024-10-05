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
        //nums_index[num]=i;
        //min_to_max[i]=num;
    }
    //min_to_max&&min_to_max_index
    // for(int i = 1; i < times_const+1; i++){
    //     cout<<nums[i]<<endl;
    // }
    // sort(min_to_max+1,min_to_max+times_const+1);
    // for(int i = 1; i <= times_const; i++){
    //     //cout<<min_to_max[i]<<endl; 
    //     min_to_max_index[min_to_max[i]]=i;
    // } 
    //遍历
    int min=nums[1];
    int max=nums[1];
    //cout<<"ans[1]:"<<ans[1]<<endl;
    //int flag=0;
    for(int left=1;left<=times_const;left++){
        min=nums[left];
        max=nums[left];
        for(int right=left;right<=times_const;right++){
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
        }
    } 
    //cout<<endl;
    for(int i = 1; i < times_const+1; i++){
        cout<<ans[i]<<" ";
    } 
    cout<<endl;
}