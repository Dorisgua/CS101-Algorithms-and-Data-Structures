//use class and hash
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#include <ctype.h>
#include <iostream>
using namespace std;
class MyLinkedList {//123ok
public:
    struct node{
        int index_has;
        int val;
        node *next;
        node(int y,int x): index_has(y),val(x),next(NULL){}
    };
    MyLinkedList() {
        head=new node(0,0);
        size=0;
        count = 0;
    }
    void addAtHead(int index_has,int val) {
        node *newnode=new node(index_has,val);
        newnode->next=head->next;
        head->next=newnode;
    }
    void action1(int index_before, int val) {
        int valid = 0;
        int a = -1;
        int b = -1;
        //先找到前一个index——has是index_before的，加在它后面
        if(index_before==0) {//加在头部
            valid = 1;
            addAtHead(count+1,val);
            node *cur=head->next;
            if(cur->next){
                b = cur->next->val;
            }
        }
        else if(index_before>count||index_before<0){
            cout<<"!"<<endl;
            return;
        }//invalid的情况
        else{//valid的情况，index_before很可能有效的情况下
            node *cur=head->next;
            node *newnode = nullptr;
            while(cur) {
                if(cur->index_has==index_before){
                    valid = 1;
                    newnode=new node(count+1,val);
                    newnode->next=cur->next;//连接index
                    if(cur->next){
                        b = cur->next->val;
                    }
                    cur->next=newnode;//连接前一个
                    //if(cur){
                    a = cur->val;
                    //}
                    break;
                }
                cur=cur->next;
            }
        }
        if(valid==1){
            size++;
            count++;
            cout<<a<<" "<<b<<endl;
        }
        else{
            cout<<"!"<<endl;
            return;
        }
    }
    void action2(int k_i,int v_i){
        int valid = 0;
        int res = -1;
        node *cur=head->next;
        while(cur) {
            if(cur->index_has==k_i){
                valid = 1;
                res = cur->val;
                cur->val = v_i;
                break;
            }
            cur=cur->next;
        }
        if(valid==1){
            cout<<res<<endl;
        }
        else{
            cout<<"!"<<endl;
        }
    }
    int action3(int num) {
        int num_of_removed = 0;
        node *pre=nullptr;
        node *cur=head;
        while(head!=nullptr&&head->val==num){
            head=head->next;
            //free(cur);
            delete cur;
            cur=head;
            num_of_removed++;
        }
        pre=head;
        cur=pre->next;
        while(cur){
            if(cur->val==num){
                pre->next=cur->next;
                delete (cur);
                cur=pre->next;
                num_of_removed++;
                size--;
            }
            else{
                pre=cur;
                cur=cur->next;
            }
        }
        return num_of_removed;
    }
    void printsize(){
        printf("size:%d\n",size);
    }
    void printa(){
        node *cur=head;
        int jishu = size;
        while(jishu--){
            cur=cur->next;
            //printf("cur->index:%d,cur->val:%d\n",cur->index_has,cur->val);
            printf("%d ",cur->val);
        }
        printf("\n");
    }
private:
    int size;
    node *head;
    int count;
};
void read(int &x)
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    //printf("%d",x);
}
int main(){
    MyLinkedList linkedList;
    int times;
    read(times);
    //printf("\n");
    while(times){
        times--;
        int action;
        read(action);
        //printf(" ");
        if(action==1){
            int k_i,v_i;
            read(k_i);
            //printf(" ");
            read(v_i);
            linkedList.action1(k_i,v_i);
            //linkedList.printa();
            //printf("\n");
        }
        else if(action==2){
            int k_i,v_i;
            read(k_i);
            //printf(" ");
            read(v_i);
            linkedList.action2(k_i,v_i);
            //linkedList.printa();
            //printf("\n");
        }
        else{
            int v_i;
            read(v_i);
            cout<<linkedList.action3(v_i)<<endl;
            //linkedList.printa();
            //printf("\n");
        }
    }
    linkedList.printa();
}
