#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#include <ctype.h>
#include <iostream>
#include<set>
#include<map>
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
    map<int,set<int>> map1;
    const int times2 = times;
    int index_after[times2];
    index_after[0] = 1;
    int val[times2];
    int count = 1;
    for(int i = 1;i<times2;i++){
        index_after[i] = -1;
    }
    while(times--){
        int action;
        read(action);
        if(action==1){
            int k_i,v_i;
            read(k_i);
            read(v_i);
            if(k_i<0||k_i>count||val[index_after[k_i]]==-1){
                cout<<"!"<<endl;
            }
            else{
                if(k_i==0){
                    map1[v_i].insert(0);
                    val[count] = v_i;
                    map1[val[index_after[0]]].erase(0);
                    map1[val[index_after[0]]].insert(1);
                    //index_after[count] = index_after[0];
                    int before = -1;
                    int after = index_after[1];
                    index_after[0] = count;
                    printf("%d %d\n",before,after);
                    count++;
                }
                else{
                    map1[v_i].insert(k_i);
                    val[count] = v_i;
                    map1[val[index_after[k_i]]].erase(k_i);
                    map1[val[index_after[k_i]]].insert(count);
                    index_after[count] = index_after[k_i];
                    int before = -1;
                    int after = -1;
                    if(val[k_i]>0){
                        before = val[k_i];
                    }
                    index_after[k_i] = count;
                    if(index_after[count]!=-1){//判断他的后面还有没有值
                        after = val[index_after[count]];
                    }
                    printf("%d %d\n",before,after);
                    count++;
                }
            }
        }
        else if(action==2){
            int k_i,v_i;
            read(k_i);
            read(v_i);
            if(k_i<0||k_i>=count||val[index_after[k_i]]==-1){
                cout<<"!"<<endl;
            }
            else{
                printf("%d\n",val[k_i]);
                map1[val[k_i]].erase(k_i);
                val[k_i] = v_i;
                map1[v_i].insert(k_i);
            }
        }
        else{
            int v_i;
            read(v_i);
            int ans = 0;
            set<int>::iterator it;
            for(it = map1[v_i].begin();it!=map1[v_i].end();it++){
                val[index_after[*it]] = -1;
                ans++;
                map1[v_i].erase(it);
            }
            printf("%d\n",ans);
        }
        // int k = 0;
        // for(int i = 1;i<count;i++){
        //     if(val[index_after[k]]<=-1){
        //     }
        //     else{
        //         printf("%d ",val[index_after[k]]);
        //     }
        //     k = index_after[k];
        // }
        // cout<<endl;
    }
    int k = 0;
        for(int i = 1;i<count;i++){
            if(val[index_after[k]]<=-1){
            }
            else{
                printf("%d ",val[index_after[k]]);
            }
            k = index_after[k];
        }
    cout<<endl;
}
