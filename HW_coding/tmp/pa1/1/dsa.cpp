#include "dsa.h"
#include <cstdlib>
#include <functional>
#include <optional>
#include<iostream>
#define TODO()                                                                 \
  do {                                                                         \
    exit(1);                                                                   \
  } while (0)
//369pass
namespace part_queue {
Queue::Queue(){
  head = 1;
  tail = 0;
}
bool Queue::empty() const { 
  return head%CAPACITY==(tail+1) % CAPACITY;
}
std::optional<Value> Queue::pop() {
  if(empty()){
    return {std::nullopt};
  }
  Value ans = data[head];
  head = (head+1) % CAPACITY;
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
}
bool Stack::empty() const {
  return (stack_top<=0);
}
std::optional<Value> Stack::pop() {
  if(empty()){
    return {std::nullopt};
  }
  Value ans = data[stack_top];
  stack_top = (stack_top-1) % CAPACITY;
  return ans;
}
void Stack::push(Value value) {
  stack_top = (stack_top+1) % CAPACITY;
  data[stack_top] = value;
}
} // namespace part_stack

// namespace part_hash_table {
// using Status = Slot::Status;
// HashTable::HashTable(std::function<size_t(Key)> hash_func):hash_func(hash_func){}
// std::array<Slot, CAPACITY> HashTable::dump() const { 
//   return slots;
// }

// bool HashTable::insert(Key key, Value value) { 
//   std::cout<<key;
//   //key = key % CAPACITY;
//   int real = hash_func(key % CAPACITY)%CAPACITY;
//   for(int i = 0;i<CAPACITY;i++){
//     if(slots[i].status==Slot::Status::occupied){
//       if(slots[i].key == key){
//         return false;
//       }
//     }
//   }
//   if(slots[real].status != Slot::Status::erased){
//     slots[real].status = Slot::Status::occupied;
//     slots[real].key = key;
//     slots[real].value = value;
//   }
//   while (slots[real].status != Slot::Status::empty){
//     real++;
//     real = (real)%CAPACITY;
//     if(slots[real].status == Slot::Status::empty){
//       slots[real].status = Slot::Status::occupied;
//       slots[real].key = key;
//       slots[real].value = value;
//       return true;
//     }
//   }
//   return true;
// }

// std::optional<Value> HashTable::lookup(Key key) const {
//   //key = key % CAPACITY;
//   int real = hash_func(key % CAPACITY)%CAPACITY;
//   if (slots[real].status == Slot::Status::occupied){
//     if (slots[real].key == key){
//       Value ans =  slots[real].value;
//       return ans;
//     }
//   }
//   while (slots[real].status != Slot::Status::empty){
//     real++;
//     real = (real)%CAPACITY;
//     if(slots[real].status == Slot::Status::occupied){
//       if(slots[real].key == key){
//         Value ans =  slots[real].value;
//         return ans;
//       }
//     }
//   }
//   return std::nullopt;
// }

// bool HashTable::erase(Key key) { 
//   //key = key % CAPACITY;
//   int real = hash_func(key % CAPACITY)%CAPACITY;
//   if (slots[real].status == Slot::Status::occupied){
//     if (slots[real].key == key){
//       slots[real].status = Slot::Status::erased;
//       return true;
//     }
//   }
//   while (slots[real].status != Slot::Status::empty){
//     real++;
//     real = (real)%CAPACITY;
//     if(slots[real].status == Slot::Status::occupied){
//       if(slots[real].key == key){
//         slots[real].status = Slot::Status::erased;
//         return true;
//       }
//     }
//   }
//   return false;
// }
// } // namespace part_hash_table
namespace part_hash_table {
using Status = Slot::Status;
HashTable::HashTable(std::function<size_t(Key)> hash_func):hash_func(hash_func) {}
std::array<Slot, CAPACITY> HashTable::dump() const { 
  return slots;
}

bool HashTable::insert(Key key, Value value) { 
  int real = hash_func(key)%CAPACITY;
  if (slots[real].status == Slot::Status::empty){
    slots[real].status == Slot::Status::occupied;
    slots[real].key = key;
    slots[real].value = value;
    return true;
  }
  if (slots[real].status = Slot::Status::occupied){
    if (slots[real].key == key){
      return false;
    }
  }
  while (slots[real].status != Slot::Status::empty){
    real++;
    real = (real)%CAPACITY;
    if(slots[real].status == Slot::Status::occupied){
      if(slots[real].key == key){
        return false;
      }
    }
    else{
      slots[real].status = Slot::Status::occupied;
      slots[real].key = key;
      slots[real].value = value;
      return true;
    }
  }
  return false;
  // int k = CAPACITY;
  // for(int i = 0;i<k;i++){
  //   if(slots[i].status==Slot::Status::occupied){
  //     if(slots[i].key == key){
  //       return false;
  //     }
  //   }
  // }
  // if(slots[real].status != Slot::Status::occupied){
  //   slots[real].status = Slot::Status::occupied;
  //   slots[real].key = key;
  //   slots[real].value = value;
  //   return true;
  // }
  // while (slots[real].status == Slot::Status::occupied){
  //   real++;
  //   real = (real)%CAPACITY;
  //   if(slots[real].status != Slot::Status::occupied){
  //     slots[real].status = Slot::Status::occupied;
  //     slots[real].key = key;
  //     slots[real].value = value;
  //     return true;
  //   }
  // }
  // return false;
}

std::optional<Value> HashTable::lookup(Key key) const {
  int real = hash_func(key)%CAPACITY;
  if (slots[real].status == Slot::Status::empty){
    return std::nullopt;
  }
  if (slots[real].status == Slot::Status::occupied){
    if (slots[real].key == key){
      Value ans =  slots[real].value;
      return ans;
    }
  }
  while (slots[real].status != Slot::Status::empty){
    real++;
    real = (real)%CAPACITY;
    if(slots[real].status == Slot::Status::occupied){
      if(slots[real].key == key){
        Value ans =  slots[real].value;
        return ans;
      }
    }
  }
  return std::nullopt;
}

bool HashTable::erase(Key key) { 
  int real = hash_func(key)%CAPACITY;
  if (slots[real].status == Slot::Status::empty){
    return false;
  }
  if (slots[real].status == Slot::Status::occupied){
    if (slots[real].key == key){
      slots[real].status = Slot::Status::erased;
      return true;
    }
  }
  while (slots[real].status != Slot::Status::empty){
    real++;
    real = (real)%CAPACITY;
    if(slots[real].status == Slot::Status::occupied){
      if(slots[real].key == key){
        slots[real].status = Slot::Status::erased;
        return true;
      }
    }
  }
  return false;
}
} // namespace part_hash_table
