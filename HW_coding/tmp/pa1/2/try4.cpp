#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#include <ctype.h>
#include <iostream>
#include <list>
#include <iterator>
using namespace std;
// struct node{//单链表节点结构
//     //int count;
//     int index_has;
//     int val;//数据域
//     node *next;//指针域
//     node(int y,int x): index_has(y),val(x),next(NULL){}
//     node(int x):val(x),next(NULL){}
// };
void read(int &x)
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    //printf("%d",x);
}
void printa(list<pair<int,int>> a){
    //printf("The list is:\n");
    list<pair<int,int>>::iterator iter;
    for (iter = a.begin(); iter != a.end(); iter++) {
        // cout <<"index:"<< iter->first << endl;
        // cout <<"val:"<< iter->second << endl;
        // cout << "--------" << endl;
        cout<<iter->second<<" ";
    }
    cout<<endl;
}
void action3(list<pair<int,int>> &a,int v_i){
    list<pair<int,int>>::iterator iter = a.begin();
    int num_of_v_i = 0;
    while(iter != a.end()){
        if(iter->second==v_i){
            iter = a.erase(iter);
            num_of_v_i++;
            iter--;
        }
        iter++;
    }
    cout<<num_of_v_i<<endl;
}
void action2(list<pair<int,int>> &a,int k_i,int v_i){
    list<pair<int,int>>::iterator iter;
    int res = -1;
    for (iter = a.begin(); iter != a.end(); iter++) {
        if(iter->first==k_i){
            res = iter->second;
            iter->second = v_i;
            cout<<res;
        }
    }
    if(res==-1){
        cout<<"!";
    }
    cout<<endl;
}
void action1(list<pair<int,int>> &a,int index_before,int v_i,int count){
    int flag = 0;
    int a1 = -1;
    int b = -1;
    list<pair<int,int>>::iterator iter = a.begin();
    if(index_before==0){
        a.push_front(make_pair(count+1,v_i));
        flag = 1;
        iter = a.begin();
        iter++;
        if(iter!=a.end()){
            b = iter->second;
        }
    }
    else if(index_before>count||index_before<0){
        cout<<"!"<<endl;
        return;
    }
    else{
        for (iter = a.begin(); iter != a.end(); iter++) {
            if(iter->first==index_before){
                flag = 1;
                a1 = iter->second;
                //list<pair<int,int>>::iterator iter2 = iter;
                //iter2++;
                iter++;
                a.insert(iter,make_pair(count+1,v_i));
                if(iter!=a.end()){
                    b = iter->second;
                }
                iter--;
                //iter2--;
                continue;
            }
        }
    }
    if(flag==1){
        cout<<a1<<" "<<b<<endl;
    }
    else{
        count--;
        cout<<"!"<<endl;
    }
}
int main(){
    list<pair<int,int>> a;
    // list<pair<int,int>>::iterator iter = a.begin();
    // a.push_front(make_pair(1,4));
    // a.push_front(make_pair(2,3));
    // //iter--;
    // cout<<iter->first;
    // cout<<iter->second;
    // // cout<<endl;
    // // for (iter = a.begin(); iter != a.end();iter++) {
    // //     cout<<iter->first;
    // //     cout<<iter->second;
    // // }

    // iter = a.begin();
    // cout<<iter->first;
    // cout<<iter->second;
    // list<pair<int,int>>::iterator iter2 = iter;
    // iter2++;
    // cout<<iter->first;
    // cout<<iter->second;
    // if(iter2==a.begin()){
    //     cout<<"iter2==a.begin()";
    // }
    // iter2--;
    // if(iter2==a.begin()){
    //     cout<<"iter2==a.begin()";
    // }
    // a.insert(iter2,make_pair(2,2));
    // a.push_front(make_pair(3,1));
    // printa(a);
    
    // cout<<iter->first;
    // cout<<iter->second;
    // iter = a.begin();
    // cout<<iter->first;
    // cout<<iter->second;
    // while(iter != a.end()){
    //     if(iter->second==6){
    //         iter = a.erase(iter);
    //         iter--;
    //     }
    //     iter++;
    //     cout<<iter->first;
    //     cout<<iter->second;
    // }


    // // action3(a,6);
    // // action2(a,1,77);
    // // printa(a);
    // action1(a,0,123,0);
    // action1(a,1,456,1);
    // action1(a,1,123,2);
    // action1(a,3,789,3);
    // action2(a,3,789);
    // action3(a,789);
    // action1(a,3,456,4);
    // //action1(a,1,3,789);
    // printa(a);
    //a.erase(iter);

    int times;
    read(times);
    int count = 0;
    while(times){
        //printa(a);
        times--;
        int action;
        read(action);
        if(action==1){
            int k_i,v_i;
            read(k_i);
            read(v_i);
            action1(a,k_i,v_i,count);
            count++;
        }
        else if(action==2){
            int k_i,v_i;
            read(k_i);
            read(v_i);
            action2(a,k_i,v_i);
        }
        else{
            int v_i;
            read(v_i);
            action3(a,v_i);
        }
        printa(a);
    }
    printa(a);
}