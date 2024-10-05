#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#include <ctype.h>
#include <iostream>
namespace part_hash_table {
const size_t CAPACITY = 100000;
using Key = size_t;
using Value = size_t;
struct Slot {
  enum class Status {
    empty,
    occupied,
    erased,
  } status;
  Key key;
  Value value;
  Slot() : status(Status::empty), key(), value() {}
  bool operator==(const Slot &s0) const {
    return status == s0.status && key == s0.key && value == s0.value;
  }
};

class HashTable {
public:
  HashTable(std::function<size_t(Key)> hash_func);
  std::array<Slot, CAPACITY> dump() const;
  bool insert(Key key, Value value);
  std::optional<Value> lookup(Key key) const;
  bool erase(Key key);

private:
  std::function<size_t(Key)> hash_func;
  std::array<Slot, CAPACITY> slots;
};
}
int main(){
    using namespace part_hash_table;
    
}