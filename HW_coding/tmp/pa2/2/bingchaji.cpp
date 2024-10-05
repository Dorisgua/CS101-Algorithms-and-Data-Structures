#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
#include <ctype.h>
#include <iostream>
#include <algorithm>
using namespace std;
class UnionFindSet{
private:
	vector<int> _ufs;
public:
	UnionFindSet(size_t n)
		:_ufs(n, -1)
	{}
	
	int FindRoot(int x)
	{
		int root = x;
		while(_ufs[root] >= 0)
		{
			root = _ufs[x];
		}
		
		//路径压缩
		while(_ufs[x] >= 0)
		{
			int parent = _ufs[x]; //记录下x的父亲节点
			_ufs[x] = root;
			
			x = parent;
		}
		
		return root;
	}	
	
	void Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		if(root1 == root2)
			return;
		
		//数据量小的往数据量大的合并
		if(abs(_ufs[root1]) < abs(_ufs[root2]))
			swap(root1, root2);
			
		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;
	}
	
	bool InSet(int x1, int x2)
	{
		return FindRoot(x1) == FindRoot(x2);
	}
	
	//集合的数量
	size_t SetSize()
	{
		size_t size = 0;
		for(size_t i = 0; i < _ufs.size(); i++)
		{
			if(_ufs[i] < 0)
			{
				++size;
			}
		}	
		
		return size;
	}
};
int main(){
    
}
