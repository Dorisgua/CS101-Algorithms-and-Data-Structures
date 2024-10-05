#include "dsa.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#define TODO()                                                                 \
  do {                                                                         \
    fprintf(stderr, "NOT IMPLEMENTED %s:%d", __FILE__, __LINE__);              \
    std::exit(1);                                                              \
  } while (0)

namespace lsort {
// void printall(const List &la)
// {
//     List a=la;
//     while(!a.empty()){
//       std::cout<<a.front()<<std::endl;
//       a.pop_front();
//     }
// }
void merge(const List &la, const List &lb, List &out) {
  //printall(out);
  //std::cout<< std::endl;
  List out1;
  //std::cout<<"in merge"<<std::endl;
  if(la.empty()){//如果la是空的，直接让out=lb
    out1=lb;
    //std::cout<<"in la.empty()"<<std::endl;
    return;
  }
  if(lb.empty()){
    out1=la;
    return;
  }
  auto ita=la.begin();
  auto itb=lb.begin();
  while(itb!=lb.end()&&ita!=la.end()){
    //std::cout<<"while"<<std::endl;
    if(*ita>*itb){
      //std::cout<<"0if(*ita>*itb){"<<std::endl;
      out1.push_front(*itb);
      //std::cout<<"1if(*ita>*itb){"<<std::endl;
      itb++;
    }
    else{
      //std::cout<<"2if(*ita<*itb){"<<std::endl;
      out1.push_front(*ita);
      //std::cout<<"3if(*ita<*itb){"<<std::endl;
      ita++;
    }
  }
  if(itb==lb.end()){
    while(ita!=la.end()){
      out1.push_front(*ita);
      ita++;
    }
  }
  if(ita==la.end()){
    while(itb!=lb.end()){
      out1.push_front(*itb);
      itb++;
    }
  }
  auto itout=out1.begin();
  while(itout!=out1.end()){
    out.push_front(*itout);
    itout++;
  }
}

void partition(const List &la, List &leq, List &gt, Key pivot) {
  auto itla=la.begin();
  //lsort::ConstIter itleq=leq.begin();
  //lsort::ConstIter itgt=gt.begin();
  while(itla!=la.end()){
    //std::cout<<pivot<<std::endl;
    //std::cout<<*itla<<std::endl;
    //std::cout<<"while"<<std::endl;
    if (*itla<=pivot){
      //std::cout<<"0if (*itla<pivot){"<<std::endl;
      leq.push_front(*itla);
      //std::cout<<"1if (*itla<pivot){"<<std::endl;
    }
    else{
      //std::cout<<"2if (*itla>pivot){"<<std::endl;
      gt.push_front(*itla);
      //std::cout<<"3if (*itla>pivot){"<<std::endl;
    }
    //std::cout<<"itla++"<<std::endl;
    itla++;
  }
}
Key select_pivot(const List &la) {
  //lsort::ConstIter itla=la.begin();
  //std::cout<<*itla<<std::endl;
  //std::cout<<"list_size(la):"<<list_size(la)<<std::endl;
  Key k1  =la.front();
  Key k2=0;
  Key k3=0;
  int k21  =random_index(list_size(la));
  // int k31  =list_size(la);
  // int jishu=list_size(la);
  // while(jishu--){
  //   if(k21==jishu){
  //     k2=*itla;
  //   }
  //   if(1==jishu){
  //     k3=*itla;
  //     break;
  //   }
  //   itla++;
  // }

  int sz=1;
  for (auto i = la.begin(); i != la.end(); i++, sz++) {
    if(sz==k21){
      k2=*i;
    }
    if((sz)==list_size(la)){
      k3=*i;
      break;
    }
  }
  //std::cout<<"k1:"<<k1<<std::endl;
  //std::cout<<"k2:"<<k2<<std::endl;
  //std::cout<<"k3:"<<k3<<std::endl;
  if(k1>=k2){
    if(k2>=k3){
      return k2;
    }
    else if(k1>=k3){
      return k3;
    }
    else{
      return k1;
    }
  }
  else{//k1<k2
    if(k2<=k3){
        return k2;
    }
    else if(k1>=k3){
      return k1;
    }
    else{
      return k3;
    }
  }
}
} // namespace lsort
