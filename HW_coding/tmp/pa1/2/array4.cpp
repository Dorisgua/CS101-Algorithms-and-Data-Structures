#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#include <ctype.h>
#include <iostream>
using namespace std;//45
void read(int &x)
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    //printf("%d",x);
}
void printa(int val[],int index_after[],int next,int count[]){
    if(count[next]>=0&&index_after[next]>0){
        if(next==0){
            printa(val,index_after,index_after[next],count);
        }
        else{
            cout<<val[next]<<" ";
            printa(val,index_after,index_after[next],count);
        }
        
    }
    else{
        if(next==0){
            return;
        }
        cout<<val[next]<<" ";
    }
    //cout<<endl;
}
int main(){
    int times;
    read(times);
    const int times2 = times;
    int index_before[times2];
    int index_after[times2];
    int val[times2];
    int count[times2];//用来erase,若count[i] = -1，则第i个进来的数（count = i的数）已经删除
    for(int i = 0;i<=times;i++){
        index_before[i] = -1;
        index_after[i] = -1;
        val[i] = -1;
        count[i] = 0;
    }
    int index = 1;
    while(times--){
        int action;
        read(action);
        if(action==1){
            int k_i,v_i;
            read(k_i);
            read(v_i);
            //最开始的时候count[k_i]都是0，
            //只有index==k_i的点超出范围或者已经被删除，不成立
            if(k_i<0||k_i>=index||count[k_i]==-1){
                cout<<"!"<<endl;
            }
            else{
                //count[0]==0;k_i==0的时候
                val[index]=v_i;//val[1] = val;
                index_after[index]=index_after[k_i];//新加入数的下一个是第k_i个数的下一个//index_after[1]=index_after[0]==-1
                index_after[k_i]=index;//第k_i个数的下一个是新加入数的位置//index_after[0]=1
                index_before[index]=k_i;//新加入数的上一个是第k_i个数的位置//index_before[1]=0
                if(index_after[index]>=0){
                    index_before[index_after[index]]=index;//新加入数的下一个的上一个是新加入数的位置//index_before[-1]=1
                }
                int ans_before = index_before[index]>=0 ? val[index_before[index]]:(-1);
                int ans_after= index_after[index]>=0 ?val[index_after[index]]:-1;
                std::cout<<ans_before;
                std::cout<<" "<<ans_after<<std::endl;
                index++;
            }
        }
        else if(action==2){
            int k_i,v_i;
            read(k_i);
            read(v_i);
            if(k_i<0||k_i>=index||count[k_i]==-1){
                cout<<"!"<<endl;
            }
            else{
                int ans = val[k_i];
                val[k_i] = v_i;
                cout<<ans<<endl;
            }
        }
        else{
            int v_i;
            read(v_i);
            int ans = 0;
            for(int i = 1;i<=index;i++){
                if(val[i]==v_i&&count[i]>=0){
                    ans++;
                    val[i]=-1;
                    count[i]=-1;
                    index_after[index_before[i]]=index_after[i];//index_after:i的上一个的下一个是i的下一个
                    index_before[index_after[i]]=index_before[i];//index_before:i的下一个的上一个是i的上一个
                    index_before[i]=-1;
                    index_after[i]=-1;
                }
            }
            cout<<ans<<endl;
        }
        //printa(val,index_after,0,count);
        // for(int i = 0;i<10;i++){
        //     cout<<index_after[i]<<" ";
        // }
        // cout<<endl;
    }
    int i = 0;
    while(index_after[i]!=-1){
        printf("%d ",val[i]);
        i = index_after[i];
    }
    cout<<endl;
}