#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int main()
{
  set<pair<int,int> > s;
  s.insert(make_pair(3,1));
  s.insert(make_pair(3,1));
  s.insert(make_pair(1,1));
  s.insert(make_pair(1,2));
  s.insert(make_pair(2,5));
  s.insert(make_pair(2,3));
  cout<<s.count(make_pair(3,1))<<endl;
  set<pair<int ,int> > ::iterator it;
  for(it=s.begin();it!=s.end();it++)
    cout<<it->first<<' '<<it->second<<"\n";
  it=s.upper_bound(make_pair(2,4));
  if(it!=s.end()){
    printf("(2,4)后面接着是 %d %d\n",it->first,it->second);
  }
  s.erase(it);//删除 
  for(it=s.begin();it!=s.end();it++)
    cout<<it->first<<' '<<it->second<<"\n";
}