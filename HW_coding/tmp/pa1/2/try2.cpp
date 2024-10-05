#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#include <ctype.h>
#include <iostream>
using namespace std;
class MyLinkedList {
public:
    struct node{//单链表节点结构
        //int count;
        int index_has;
        int val;//数据域
        node *next;//指针域
        node(int y,int x): index_has(y),val(x),next(NULL){}//表示的含义就是节点数值为x，指针为空（初始化一个新节点）
    };
    MyLinkedList() {//初始化链表
        head=new node(0,0);//初始化头指针，数据为0(0-0(index))--->相当于定义了一个空节点作为头，它本身不算节点
        size=0;//链表长度为0
        count = 0;
    }
    void addAtHead(int index_has,int val) {//插入头
        node *newnode=new node(index_has,val);//创建新节点
        newnode->next=head->next;//将头节点的next赋值给新的节点--->相当于连接新插入节点与第一个节点
        head->next=newnode;//连接头指针与第一个新节点
    }
    void action1(int index_before, int val) {
        int valid = 0;
        int a = -1;
        int b = -1;
        //先找到前一个index——has是index_before的，加在它后面
        if(index_before==0) {//加在头部
            valid = 1;
            addAtHead(count+1,val);
        }
        else if(index_before>count||index_before<0){}//invalid的情况
        else{//valid的情况，index_before很可能有效的情况下
            size++;
            int jishu = size;
            node *cur=head;
            node *newnode = nullptr;
            while(jishu--) {
                if(cur->index_has==index_before){
                    valid = 1;
                    newnode=new node(count+1,val);
                    break;
                }
                cur=cur->next;
            }
            if(valid==1){
            newnode->next=cur->next;//连接index
            cur->next=newnode;//连接前一个
            if(newnode->next){
                b = newnode->next->val;
            }
            if(cur){
                a = cur->val;
            }
            }
            size--;
        }
        if(valid==1){
            size++;
            count++;
            cout<<a<<" "<<b<<endl;
        }
        else{
            cout<<"!"<<endl;
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
            count++;
        }
        else{
            cout<<"!"<<endl;
        }
    }
    int action3(int num) {
        int num_of_removed = 0;
        node *pre=NULL;
        node *cur=head;
        while(head!=NULL&&head->val==num){
            head=head->next;
            free(cur);
            cur=head;
        }
        pre=head;
        cur=pre->next;
        while(cur){
            if(cur->val==num){
                pre->next=cur->next;
                free(cur);
                cur=cur->next;
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
    int size;//表示链表长度
    node *head;//定义头指针
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