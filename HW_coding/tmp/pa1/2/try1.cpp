#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
typedef struct Node //链表节点定义
{
    void *data;        //节点的数据域，存址
    struct Node *next; //指针域，保存下一个节点的地址，指向下一个节点
} Node;
typedef struct Student//后续的测试用例，假定链表存储该数据类型
{
    int id;
    char name[20];
} Student;
 
typedef struct LinkList //链表
{
    Node firstNode; //链表的首个节点
    int size;       //链表长度
} List;
List *initLinkList() //链表初始化
{
    List *list = (List *)malloc(sizeof(List));//向堆区申请内存
    if (list == NULL)
        return NULL;
    list->firstNode.data = NULL;//初始化
    list->firstNode.next = NULL;
    list->size = 0;
    return list;
}
Node *createSingleNode(void *data) //创建节点
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
Node *insertSingleNodeByHead(void *data, List *list) //单链表有表头头插法
{
    if (data == NULL || list == NULL)//空指针判断
        return NULL;
    Node *node = createSingleNode(data);
    node->next = list->firstNode.next;
    list->firstNode.next = node;
    list->size++;//链表容量+1
    return node;
}
Node *insertSingleNodeByTail(void *data, List *list) //单链表尾插法
{
    if (data == NULL || list == NULL)
        return NULL;
    Node *node = createSingleNode(data);
    Node *pointer = &(list->firstNode);//拿到首节点的地址
    while (pointer->next)
        pointer = pointer->next;
    pointer->next = node;//此时pointer是最后一个节点
    node->next = NULL;//node成为最后一个节点
    list->size++;
    return node;
}

Node *insertSingleNodeByIndex(void *data, int index, List *list)//根据索引index插入数据data至链表中
{
    if (data == NULL || list == NULL)
        return NULL;
    if (index < 0 || index > list->size) // 0索引为无有效数据的firstNode
        index = list->size;              //非法索引时，统一尾插处理
    Node *node = createSingleNode(data);
    Node *firstN = &list->firstNode;//拿到首节点地址
    for (int i = 0; i < index; i++)
        firstN = firstN->next;
    node->next = firstN->next;
    firstN->next = node;
    list->size++;
    return node;
}
void printfList(void *data) //为方便函数回调，写此函数方便提供程序的可扩展性
{
    Student *stu = (Student *)data;
    printf("name:%s-id:%d--->\t", stu->name, stu->id );
}
void listNode(List *list, void (*printfList)(void *)) //节点遍历
{
    if (list == NULL)
        return;
    Node *pointer = list->firstNode.next; //默认头节点未保留有效数据，list->firstNode.next为第一个有效节点
    while (pointer)
    {
        printfList(pointer->data);//传入的是pointer->data,不是pointer
        pointer = pointer->next;
    }
    puts("\n");
}
int compare(void *s1, void *s2) //为Student类型数据设计compare比较函数
{
    Student *stu1 = (Student *)s1;
    Student *stu2 = (Student *)s2;
    if (strcmp(stu1->name, stu2->name) == 0 && stu1->id == stu2->id)
        return 1;
    return 0;
}
int deleteSingleNode(void *deleteData, List *list, int (*compare)(void *, void *)) //单链表删除节点
{
    Node *pointer = &(list->firstNode);
    while (pointer->next)
    {
        if (compare(pointer->next->data, deleteData)) // pointer->next->data而不是pointer->next
        {//pointer->next即为需要删除节点
            Node *deleteNode = pointer->next;
            pointer->next = pointer->next->next;
            free(deleteNode); //释放删除节点占用的堆内存
            deleteNode = NULL;
            list->size--;
            return 1;
        }
        pointer = pointer->next;
    }
    return 0; //删除失败返回0
}
int main()
{
    Student stu[] = {
        {1, "jakes1"},
        {2, "jakes2"},
        {3, "jakes3"},
        {4, "jakes4"},
        {5, "jakes5"},
        {6, "jakes6"},
        {7, "jakes7"},
        {8, "jakes8"},
    };
    //Student ss = {6, "sd"};
    List *list = initLinkList();
    for (int i = 0; i < 3; i++)
        insertSingleNodeByHead(&stu[i], list); //头插节点
    listNode(list, printfList);
    for (int i = 3; i < 6; i++)
        insertSingleNodeByTail(&stu[i], list); //尾插节点
    listNode(list, printfList);
    for (int i = 6; i < 8; i++)
        insertSingleNodeByIndex(&stu[i],2,list); //根据索引插入
    listNode(list, printfList);
    for (int i = 2; i < 4; i++)
        deleteSingleNode(&stu[i], list, compare); //删除节点
    listNode(list, printfList);                   //遍历节点
    return 0;
}