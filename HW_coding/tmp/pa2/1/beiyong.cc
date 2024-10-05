lsort::ConstIter ita=la.begin();
  lsort::ConstIter itb=lb.begin();
  lsort::ConstIter itout=out.begin();
  lsort::ConstIter itout_before=out.before_begin();
  std::cout<<"in lsort::ConstIter"<<std::endl;
  while(itb!=lb.end()&&ita!=la.end()){
      std::cout<<"in itb!=lb.end()&&ita!=la.end()"<<std::endl;
      std::cout<<*ita<<*itb<<std::endl;
      if(*ita>*itb){
        if(itout==out.end()){
          std::cout<<"0out.insert_after(itout,*itb);";
          out.insert_after(itout_before,*itb);
          std::cout<<out.front()++<<std::endl;
          std::cout<<"-0out.insert_after(itout,*itb);";
        }
        else{
          std::cout<<"1out.insert_after(itout,*itb);";
          out.insert_after(itout,*itb);
          std::cout<<"2out.insert_after(itout,*itb);";
        }
        std::cout<<"itb++;";
        itb++;
      }
      else{
        if(itout==out.end()){
          std::cout<<"-1out.insert_after(itout,*ita);";
          out.insert_after(itout_before,*ita);
          std::cout<<out.front()++<<std::endl;
          std::cout<<"-2out.insert_after(itout,*ita);";
        }
        else{
          std::cout<<"3out.insert_after(itout,*ita);";
          out.insert_after(itout,*ita);
          std::cout<<"4out.insert_after(itout,*ita);";
        }
        ita++;
      }
      std::cout<<"itout++;";
      itout++;
  }
  std::cout<<"if(itb==lb.end()){";
  if(itb==lb.end()){
    while(ita!=la.end()){
      out.insert_after(itout,*ita);
      ita++;
      itout++;
    }
  }
  if(ita==la.end()){
    while(itb!=lb.end()){
      out.insert_after(itout,*itb);
      itb++;
      itout++;
    }
  }