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
    int times;
    read(times);
    const int times2 = times;
    int index_before[times2];
    int index_after[times2];
    int val[times2];
    int count[times2];//用来erase
    for(int i = 0;i<=times;i++){
        index_before[i] = -1;
        index_after[i] = -1;
        val[i] = -1;
        count[i] = 2;
    }
    
    int index = 1;
    while(times--){
        int action;
        read(action);
        if(action==1){
            int k_i,v_i;
            read(k_i);
            read(v_i);
            cout<<"index:"<<index<<" ;";
            cout<<"count[k_i]:"<<count[k_i]<<" ;";
            if(k_i<0||k_i>=index||count[k_i]==-1){
                cout<<"!"<<endl;
            }
            else{
                int ans_before = -1;
                int ans_after = -1;
                val[index]=v_i;
                // index_after[index]=index_after[k_i];//新加入数的下一个是第k_i个数的下一个//index_after[1]=index_after[0]==-1
                // index_after[k_i]=index;//第k_i个数的下一个是新加入数的位置//index_after[0]=1
                // //index_before
                // index_before[index]=k_i;//新加入数的上一个是第k_i个数的位置////index_before[1]=0
                // cout<<index_after[index]<<endl;
                // if(index_after[index]>0){//index_after[index]=-1;index_after[2]=-1
                //     index_before[index_after[index]]=index;//新加入数的下一个的上一个是新加入数的位置//index_before[-1]=1
                //     ans_before =val[index_before[index]];
                // }
                // if(index_after[index]>0){
                //     ans_after=val[index_after[index]];
                // }
                //index_before[index]=k_i;
                index_after[index]=index_after[k_i];
                cout<<ans_before;
                cout<<" "<<ans_after<<endl;
                index++;
                cout<<"action1";
            }
        }
        else if(action==2){
            int k_i,v_i;
            read(k_i);
            read(v_i);
            if(k_i<0||k_i>index||count[k_i]==-1){
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
            for(int i=1;i<=index;i++){
                if(val[i]==v_i){
                    cout<<"action3";
                    val[i] = -1;
                    count[i] = -1;
                    //index_after:i的上一个的下一个是i的下一个
                    index_after[index_before[i]]=index_after[i];
                    //index_before:i的下一个的上一个是i的上一个
                    index_before[index_after[i]]=index_before[i];
                    index_before[i]=-1;
                    index_after[i]=-1;
                    ans++;
                }
            }
            //cout<<ans<<endl;
            printf("%d\n",ans);
        }
        //printa(val,index_after,0);
        cout<<"index_after"<<endl;
        for(int i = 0;i<10;i++){
            cout<<index_after[i]<<" ";
        }
        cout<<endl;
    }
    // cout<<"index_after"<<endl;
    // for(int i = 0;i<10;i++){
    //     cout<<index_after[i]<<" ";
    // }
    // cout<<endl;
    int i = 0;
    //cout<<index_after[i];
    while(index_after[i]!=-1){
        cout<<index_after[i];
        i = index_after[i];
        printf("%d ",val[i]);
    }
    // for(int i = 0;i<10;i++){
    //     cout<<index_after[i]<<" ";
    // }
    // cout<<endl;
}