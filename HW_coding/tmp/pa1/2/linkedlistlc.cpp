#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#include <ctype.h>
#include <iostream>
using namespace std;
class MyLinkedList {
public:
    /** Initialize your data structure here. */
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
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    /* int get(int index) {//获取索引节点数值
        if(index<0||index>(size-1)) return -1;//索引比0小或者比最大索引大，返回-1
        node *cur=head->next;//辅助指针指向第一个节点
        while(index--) cur=cur->next;//循环index次遍历到第index个节点
        return cur->val;//指向数值输出
    } */
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int index_has,int val) {//插入头
        node *newnode=new node(index_has,val);//创建新节点
        newnode->next=head->next;//将头节点的next赋值给新的节点--->相当于连接新插入节点与第一个节点
        head->next=newnode;//连接头指针与第一个新节点
        //size++;//长度加1
        //count++;//长度加1
    }
    
    /** Append a node of value val to the last element of the linked list. */
    /* void addAtTail(int val,int index_has) {//插入尾
        node *cur=head;//辅助指针从头指针开始
        while(cur->next) cur=cur->next;//遍历到最后一个节点,如果是空链表，则直接不循环，指针还是在头指针
        node *newnode=new node(val,index_has);//创造新节点并赋值
        newnode->next=cur->next;//复制原最后节点的next信息
        cur->next=newnode;//连接最后一个新节点和上一个节点
        size++;//长度加1
        count++;//长度加1
    } */
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int index_has,int val) {
        // if(index<=0) addAtHead(val,);//插入index的时候，如果下标是=0,就相当于从头插入，所以要包含<=
        // else if(index==size) addAtTail(val);
        // else if(index>size) return ;
        // else{
            node *newnode=new node(index_has,val);
            node *cur=head;//辅助指针从头指针开始
            while(index--) cur=cur->next;//遍历到第index-1的节点，循环次数是index次 但是辅助指针是从头指针开始而不是第一个节点
            newnode->next=cur->next;//连接index
            cur->next=newnode;//连接前一个
            size++;//长度+1
        // }
    }
    void addAtIndex2(int index_before, int val) {
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
            node *cur=head;
            node *newnode = nullptr;
            while(cur) {
                if(cur->index_has==index_before){
                    valid = 1;
                    newnode=new node(count+1,val);
                    newnode->next=cur->next;//连接index
                    cur->next=newnode;//连接前一个
                    if(newnode->next){
                        b = newnode->next->val;
                    }
                    if(cur){
                        a = cur->val;
                    }
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
        //int jishu = size;
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
    void deleteAtIndex(int index) {
        if(index<0||index>=size) return;
        node *cur=head;//从头指针开始
        while(index--){//遍历到index-1的位置,循环次数是index次
            cur=cur->next;
        }
        cur->next = cur->next->next;//相当于直接跨过了index节点
        size--;
    }
    int delete_allval(int num) {
        int num_of_removed = 0;
        node *pre=nullptr;
        node *cur=head;
        //cout<<"head->val:"<<head->val<<endl;
    while(head!=nullptr&&head->val==num){
        head=head->next;
        free(cur);
        cur=head;
    }
    pre=head;
    cur=pre->next;
    while(cur){
        if(cur->val==num){
            pre->next=cur->next;
            node *del = cur;
            //free(cur);
            cur=cur->next;
            delete del;
            num_of_removed++;
            size--;
        }else{
            pre=cur;
            cur=cur->next;
        }
    }
        return num_of_removed;
        // node *cur1=head->next;//从头指针开始
        // while(size-num_of_removed-1&&cur1){
        //     int jishu = 0;
        //     node *p2=cur1;//从头指针开始
        //     while(p2->val!=val&&p2){
        //         p2 = p2->next;
        //         jishu++;
        //     }
        //     cout<<jishu<<" ";
        //     if(p2->val==val){
        //         num_of_removed++;
        //         deleteAtIndex(jishu);
        //     }else{
        //         cur1=cur1->next;
        //     }
        // }
        // return num_of_removed;
    }
    void printsize(){
        printf("size:%d\n",size);
    }
    void printa(){
        node *cur=head;
        int jishu = size;
        while(jishu--){
            cur=cur->next;
            printf("cur->index:%d,cur->val:%d\n",cur->index_has,cur->val);
        }
    }
private://私人函数定义
    int size;//表示链表长度
    node *head;//定义头指针
    int count;
};
int main(){
    //MyLinkedList linkedList;
    //*linkedList= new MyLinkedList();
    MyLinkedList linkedList;
    //linkedList.printa();
    linkedList.addAtIndex2(0,123);
    //linkedList.addAtIndex2(0,123);
    //linkedList.addAtIndex2(1,789);
    linkedList.addAtIndex2(1,456);
    linkedList.addAtIndex2(1,123);
    linkedList.addAtIndex2(3,789);
    //linkedList.addAtIndex2(3,789);
    // cout<<"printa"<<endl;
    // linkedList.printa();
    // cout<<"end"<<endl;
    linkedList.action2(3,789);
    //linkedList.addAtIndex2(4,789);
    //linkedList.addAtIndex2(4,456);
    //linkedList.printsize();
    // cout<<"printa"<<endl;
    linkedList.printa();
    // cout<<"end"<<endl;
    //linkedList.deleteAtIndex(3);
    //cout<<linkedList.delete_allval(456)<<endl;
    cout<<linkedList.delete_allval(789)<<endl;
    linkedList.printa();
    linkedList.addAtIndex2(3,456);
    //linkedList.printsize();
    /* linkedList.addAtTail(3);
    linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3 */
    linkedList.printa();
    /* linkedList.get(1);            //返回2
    linkedList.deleteAtIndex(1);  //现在链表是1-> 3
    //linkedList.printa();
    linkedList.get(1);            //返回3 */
    //linkedList.printa();

}

