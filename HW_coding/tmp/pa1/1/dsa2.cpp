#include "dsa.h"
#include <cstdlib>
#include <functional>
#include <optional>
#include<iostream>
#define TODO()          //369pass                                                       \
  do {                                                                         \
    exit(1);                                                                   \
  } while (0)

namespace part_queue {
Queue::Queue(){
  head = -1;
  tail = 0;
  data = {};
}
bool Queue::empty() const { 
  return head==(tail-1);
}
std::optional<Value> Queue::pop() {
  if(empty()){
    return {std::nullopt};
  }
  Value ans = data[head];
  //data[head] = -1;
  head = (head+1)%CAPACITY;
  return ans;
}
void Queue::push(Value value) { 
  tail = (tail+1)%CAPACITY;
  data[tail] = value;
}
} // namespace part_queue

namespace part_stack {
Stack::Stack(){
  stack_top = 0;
  data = {};
}
bool Stack::empty() const {
  return (stack_top<=0);
}
std::optional<Value> Stack::pop() {
  if(empty()){
    return {std::nullopt};
  }
  Value ans = data[stack_top];
  data[stack_top] = {};
  stack_top = (stack_top-1)%CAPACITY;
  return ans;
}
void Stack::push(Value value) {
  stack_top = (stack_top+1)%CAPACITY;
  data[stack_top] = value;
}
} // namespace part_stack

namespace part_hash_table {
using Status = Slot::Status;
HashTable::HashTable(std::function<size_t(Key)> hash_func) {
  //hash_func = hash_func;
  //std::cout<<hash_func(key)<<std::endl;
  //slots[0].status = Slot::Status::empty;
  slots[0] = Slot();
  //slot[n],n++,一个举动

}
std::array<Slot, CAPACITY> HashTable::dump() const { 
  return slots;
}

bool HashTable::insert(Key key, Value value) { 
  if(key>=CAPACITY){
    key = key % CAPACITY;
  }
  std::cout<<hash_func(key)<<std::endl;
  if (slots[hash_func(key)].status == Slot::Status::occupied){
    return false;
  }
  slots[hash_func(key)].key=hash_func(key);
  slots[hash_func(key)].status=Slot::Status::occupied;
  slots[hash_func(key)].value=value;
  return true;
}

std::optional<Value> HashTable::lookup(Key key) const {
  if (slots[hash_func(key)].status == Slot::Status::occupied){
    Value ans =  slots[hash_func(key)].value;
    return ans;
  }
  return std::nullopt;
}

bool HashTable::erase(Key key) { 
  if (slots[hash_func(key)].status == Slot::Status::occupied){
    slots[hash_func(key)].status = Slot::Status::erased;
    return true;
  }
  return false;
}
} // namespace part_hash_table
