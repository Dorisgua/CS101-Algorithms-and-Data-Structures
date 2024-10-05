#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
void read(int &x)
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    //printf("%d",x);
}
void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main(){
    int n,q;
    read(n);
    read(q);
    const int n_const=n;
    set<int> s[n_const+1];
    int min_point=100;
    int min_point_index=100;
    int val_array[n_const+1];
    for(int i=1;i<=n;i++){
        int val; 
        read(val);
        val_array[i]=val;
        s[i].insert(val);
        if(min_point>val){
            min_point=val;
            min_point_index=i;
        }
        //printSet(s[i]);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<val_array[i]<<endl;
    // }
    //int index1_array[n_const];
    //int index2_array[n_const];
    //int set_number=0;
    for(int i=1;i<n;i++){
        int index1,index2; 
        read(index1);
        read(index2);
        if(index1>index2){
            int swap_=index2;
            index2=index1;
            index1=swap_;
            //swap(index1,index2);
        }
        // index1_array[i]=index1;
        // index2_array[i]=index2;
        // if(index1==min_point_index){
        //     //set_number++;
        // }
        if(index1!=min_point_index){
            if(val_array[index1]==val_array[index2]){
                continue;
            }
            else{
                int delete_set_index=val_array[index2];
                for (set<int>::iterator it = s[delete_set_index].cbegin(); it != s[delete_set_index].cend(); it++)
	            {
		            val_array[*it]=val_array[index1];
                    cout<<"val_array[*it]:"<<val_array[*it]<<" ";
	            }
                cout<<endl;
                s[val_array[index1]].insert(s[val_array[index2]].begin(),s[val_array[index2]].end());
            }
        }
    }
    // //第一遍先尝试如果两端不是1，看看能不能成为一个set
    // //用set的同时增加一个array，里面响应的点的数是一个。 
    for(int i=1;i<=q;i++){
        int num1,num2; 
        read(num1);
        read(num2);
        if(val_array[num1]==val_array[num2]){
            cout<<"David"<<endl;
            continue;
        }
        if(num1==min_point_index||num2==min_point_index){
            cout<<"Abigail"<<endl;
            continue;
        }
        else{
            cout<<"David"<<endl;
            continue;
        }
    }
}