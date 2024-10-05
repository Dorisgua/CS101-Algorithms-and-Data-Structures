#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <iostream>
#include <queue>
using namespace std;
void read(int &x)//过了前四个点
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
}
int main(){
    int times;
    read(times);
    const int times_const = times;
    int nums[times_const+1];
    int ans[times_const+1];
    queue<int> kaishi;
    queue<int> jieshu;
    int flag_shangyige=0;
    for(int i = 1;i<=times_const;i++){
        ans[i]=0;
        int num;
        read(num);
        nums[i]=num;
        if(i==times_const){
            continue;
        }
        else{
            if(nums[i+1]==(nums[i]+1)||nums[i+1]==(nums[i]-1)){
                if(flag_shangyige==1&&(i+1)==times_const){
                    jieshu.push(i+1);
                }
                if(flag_shangyige==0){
                    kaishi.push(i);
                }
                else{}//flag=1;
                flag_shangyige=1;
            }
            else{
                if(flag_shangyige==1){
                    jieshu.push(i);
                }
                flag_shangyige=0;
            }
        }
    }
    int min=nums[1];
    int max=nums[1];
    int left=1;
    while(left<=times_const){
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
        while(right<=shangyige_index){
            if(kaishi.empty()||right!=kaishi.front()){
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
            else{//right==kaishi.front()
                if(max<nums[kaishi.front()]){
                    max=nums[kaishi.front()];
                }
                if(min>nums[kaishi.front()]){
                    min=nums[kaishi.front()];
                }
                right=kaishi.front();
                //cout<<"max:"<<max<<endl; 
                //cout<<"min:"<<min<<endl; 
                //cout<<"right:"<<right<<endl; 
                //cout<<"left:"<<left<<endl; 
                if((max-min)==(right-left)){
                    ans[left]+=(jieshu.front()-kaishi.front());
                }
                //cout<<"left:"<<left<<" ans[left]:"<<ans[left]<<endl;
                //cout<<"right:"<<right<<endl; 
                if(max<nums[jieshu.front()]){
                    max=nums[jieshu.front()];
                }
                if(min>nums[jieshu.front()]){
                    min=nums[jieshu.front()];
                }
                jieshu.pop();
                kaishi.pop();
            }
        }
        left++;
    } 
    for(int i = 1; i < times_const+1; i++){
        cout<<ans[i]<<" ";
    } 
    cout<<endl;
}