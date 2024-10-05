#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <iostream>
#include <queue>
using namespace std;
void read(int &x)//过了前ba个点
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
}
int max_(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int min_(int a,int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}
int main(){
    int times;
    read(times);
    const int times_const = times;
    int nums[times_const+1];
    int ans[times_const+1];
    int judge_consistent[times_const+1];
    for(int i = 1;i<=times_const;i++){
        ans[i]=0;
        judge_consistent[i]=0;
        int num;
        read(num);
        nums[i]=num;
    }

    int i=1;
    while(i<times_const){
    //for(int i = 1;i<times_const;i++){
        int j=i+1;
        if(nums[j]==(nums[j-1]+1)){
            while(j<times_const&&nums[j+1]==(nums[j]+1)){
                j++;
            }
            judge_consistent[i]=j-i;
            i=j;
        }
        else if(nums[j]==(nums[j-1]-1)){
            while(j<times_const&&nums[j+1]==(nums[j]-1)){
                j++;
            }
            judge_consistent[i]=-(j-i);
            i=j;
        }
        else{
            i++;
        }
    }
    int min=nums[1];
    int max=nums[1];
    int left=1;
    while(left<=times_const){
        //cout<<"left:"<<left<<endl;
        min=nums[left];
        max=nums[left];
        int right=left;
        int shangyige_index=times_const;
        if(left==1){
            shangyige_index=times_const;
        }
        else if(nums[left-1]>nums[left]){
            //shangyige_index=nums[right-1]+left;
            //if(nums[right-1]+left<times_const){
                //shangyige_index=nums[right-1]+left;
            //}
            //shangyige_index=min(nums[right-1]+left,)
            shangyige_index=min_(nums[left-1]+left,times_const);
        }
        else if(nums[left-1]<nums[left]){
            shangyige_index=times_const;
        }
        else{}
        while(right<=shangyige_index){
            int flag=0;
            if(nums[right]<min){
                min=nums[right];
            }
            if(nums[right]>max){
                max=nums[right];
            }
            if((max-min)==(right-left)){
                //ans[left]++;
                flag=1;
            }
            //判断是否在right这点成功，如果成功的话
            if(flag==1){
                if(judge_consistent[right]>0){
                    judge_consistent[right+1]=judge_consistent[right]-1;
                    ans[left]+=judge_consistent[right];
                    right=right+judge_consistent[right];
                    max=nums[right];
                    //cout<<"haha";
                }
                else if(judge_consistent[right]<0){
                    judge_consistent[right+1]=judge_consistent[right]+1;
                    ans[left]-=judge_consistent[right];
                    right=right-judge_consistent[right];
                    min=nums[right];
                }
                else{
                    ans[left]++;
                    right++;
                }
            }
            else{
                right++;
            }
            //cout<<min<<endl;
            //cout<<max<<endl;
        }
        left++;
    }
    for(int i = 1; i < times_const+1; i++){
        cout<<ans[i]<<" ";
    } 
    cout<<endl;
}