#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
void read(int &x)
{
    auto c=getchar();x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);x=(x<<1)+(x<<3)+(c^'0'),c=getchar());
    printf("%d",x);
}
int main(){
    int x;
    FILE *fpRead=fopen("C://Users//doris//Desktop//A//list_sample.in","r");//其中"r"是表示"读",这里一定要换成自己的文件路径
    if(fpRead==NULL)
    {
        printf("读取文件错误！！！");
        return 0;
    }
    fscanf(fpRead,"%d ",&x);//读取出第一个数字为数据的数量，可以视自己的情况删除这一句
    int a[70]={0};//数组初始化
    for(int i=0;i<x;i++)
    {
        fscanf(fpRead,"%d ",&a[i]);
        if(a[i]==1){

        }
    }
}
// 7
// 1 0 123
// 1 1 456
// 1 1 123
// 1 3 789
// 2 3 789
// 3 789
// 1 3 456

// -1 -1
// 123 -1
// 123 456
// 123 456
// 123
// 2
// !
// 123 456


