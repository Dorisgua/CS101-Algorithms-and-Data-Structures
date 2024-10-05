//use class and hash
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#include <ctype.h>
#include <iostream>
using namespace std;
template <typename Type>
class Single_node {
	private:
		Type element;
		int next_node;
	public:
		Type retrieve() const{
            return element;
        }
		int next() const{
            return next_node;
        }
};
//template <typename Type>::const int Single_list::NULLPTR = -1;
template <typename Type>
class Single_list {
    private:
        int list_capacity;
        int list_head;
        int list_tail;
        int list_size;
        Single_node<Type> *node_pool;

        static const int NULLPTR;
    public:
        Single_list( int =  16);
        // member functions
        void insert(int index_before,int value){
            if (index_before==0){
                //node_pool(new Single_node<Type>[value])
                list_size++;
                list_head++;
                list_tail++;
            }
            else{
                
            }
        }
        void printa(){
            //cout<<endl;
            for(int i = list_head;i<=list_tail;i++){
                cout<<node_pool->retrieve();
                node_pool = node_pool->next();
            }
        }
};
template <typename Type> Single_list<Type>::Single_list( int n ):list_capacity( n ),list_head( NULLPTR ),list_tail( NULLPTR ),list_size(0),node_pool(new Single_node<Type>[n]) {}


int main(){

    Single_list<int> a(100);
    a.insert(0,2);
    a.printa();

}
