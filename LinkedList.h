
#ifndef _LinkedList_h_
#define _LinkedList_h_

#include <iostream>

using namespace std;

struct List
{

    int data;
    List *next;
};

void outputList(List *L)
{
    List *p = L->next;
    if (p == NULL)
    {
        cout << "表为空！";
    }
    while (p != NULL)
    { // 遍历打印出单链表元素
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void InitList(List *&L)
{
    L = new List;
    L->next = NULL;
}

void InputList(List *&L)
{
    int i, n;
    int x;
    List *u, *t;
    L = new List;
    L->next = NULL;
    t = L;
    cout << "输入节点数" << endl;
    cin >> n;
    cout << "插入数据" << endl;
    for (int i = n; i > 0; i--)
    {
        u = new List;
        cin >> x;
        u->data = x;
        u->next = NULL;
        t->next = u;
        t = u;
    }
}

void Insert(List *head, int n, int x)
{

    int i = 0;
    List *t = head;

    while (i != n - 1 && t != NULL)
    {
        t = t->next;
        i++;
    }

    if (t == NULL)
    {
        cout << "序号错误" << endl;
        return;
    }

    else
    {
        List *s = new List;
        s->data = x;
        s->next = t->next;
        t->next = s;
    }
}

void Delete(List *head, int n)
{

    int i = 0;
    List *t = head;

    while (i != n - 1 && t != NULL)
    {

        t = t->next;
        i++;
    }

    if (t == NULL || t->next == NULL)
    {

        cout << "序号错误" << endl;
    }

    else
    {

        List *u = t->next;
        t->next = u->next;
        delete u;
    }
}

void UpInsert(List *head, int x)
{

    List *t = head;

    while (t->next != NULL)
    {

        if (x < t->next->data)
        {
            break;
        }

        else
        {
            t = t->next;
        }
    }

    List *u = new List;
    u->data = x;
    u->next = t->next;
    t->next = u;
}

void Seperate(List *head, List *L1, List *L2)
{

    List *p = head->next;
    List *t;
    List *m = L1;
    List *n = L2;

    while (p != NULL)
    {

        if (p->data % 2 == 0) //如果数据为偶数
        {

            t = new List;           //申请新的节点
            t->data = p->data;      //保存数据
            t->next = m->next;      //向后链接
            m->next = t;            //向前链接
            m = t;                  //指针向后移一位
        }

        else //如果为奇数
        {

            t = new List;//申请新的节点
            t->data = p->data;//保存数据
            t->next = n->next;//向后链接
            n->next = t;//向前链接
            n = t;//指针向后移一位
        }

        p = p->next;
    }
}

void ListBoth(List *L1, List *L2, List *L3)
{
    List *a, *b, *c;
    a = L1->next;
    b = L2->next;
    c = L3;
    while (a != NULL && b != NULL) //如果都没遍历完
    {
        if (a->data > b->data)//如果a表值大b表向后移
        {
            b = b->next;
        }
        else if (a->data < b->data)//如果b表值小a表向后移
        {
            a = a->next;
        }
        else//两个值相等插入数据
        {
            List *u = new List;
            u->data = a->data;
            u->next = NULL;
            c->next = u;
            c = u;
            a = a->next;
            b = b->next;
        }
    }
}

void RepeatDelete(List *L1)
{

    List *p, *q;
    p = L1->next;
    q = L1->next->next;
    while (q)//没遍历完的情况下
    {
        if (p->data == q->data)//如果相同的话直接删除
        {
            q = q->next;
            p->next = q;
        }
        else//如果不同则指针向后移
        {
            p = p->next;
            q = q->next;
        }
    }
    cout << "删除后的链表L为:";
    outputList(L1);
    delete L1;
}

void ListAdd(List *L1, List *L2)
{
    List *u, *p, *m, *n;
    u = L1;
    p = L2;
    m = L1->next;
    n = L2->next;
    while ((m != NULL) && (n != NULL)) // 往L1中插入L2元素
    {
        if (m->data == n->data)
        {
            u = u->next;
            p = p->next;
            m = m->next;
            n = n->next;
        }
        else if (m->data < n->data)
        {
            u = u->next;
            m = m->next;
        }
        else
        {
            p->next = n->next; // 要插入L1中的结点从L2中删除掉
            u->next = n;       // L2中元素较小的结点插入到L1中元素较大的结点的前面
            n->next = m;
            u = u->next; // u指针指向L1中新的结点
            n = p->next; // n指针指向L2中新的结点
        }
    }
    if (m == NULL)
    {
        u->next = p->next; // 当L1先为空时，将L2中p->next 及以后的元素连接在L1的末尾，注意，这里不能用m = n;
    }
    delete[] L2; // 销毁L2头结
}

void test01()
{
    List *head;
    InitList(head);
    InputList(head);
    int a;
    int b;
    cout << "位置和数据" << endl;
    cin >> a >> b;
    Insert(head, a, b);
    cout << "插入后数据" << endl;
    outputList(head);
}

void test02()
{
    List *head;
    InitList(head);
    InputList(head);
    outputList(head);
    int a;
    cout << "节点位置" << endl;
    cin >> a;
    Delete(head, a);
    outputList(head);
}

void test03()
{
    List *head;
    InitList(head);
    InputList(head);
    outputList(head);
    int a;
    cout << "插入数据" << endl;
    cin >> a;
    UpInsert(head, a);
    outputList(head);
}

void test04()
{
    List *head;
    InitList(head);
    List *L1;
    InitList(L1);
    List *L2;
    InitList(L2);
    InputList(head);
    cout << "原表" << endl;
    outputList(head);
    Seperate(head, L1, L2);
    cout << "偶数表" << endl;
    outputList(L1);
    cout << "奇数表" << endl;
    outputList(L2);
}

void test05()
{
    List *L1;
    InitList(L1);
    List *L2;
    InitList(L2);
    List *L3;
    InitList(L3);
    InputList(L1);
    InputList(L2);
    outputList(L1);
    outputList(L2);
    ListBoth(L1, L2, L3);
    cout << "交集数据" << endl;
    outputList(L3);
}

void test06()
{
    List *L1;
    InitList(L1);
    InputList(L1);
    outputList(L1);
    RepeatDelete(L1);
}

void test07()
{
    List *L1;
    List *L2;
    InputList(L1);
    InputList(L2);
    cout << "原链表" << endl;
    outputList(L1);
    outputList(L2);
    ListAdd(L1, L2);
    cout << "新链表" << endl;
    outputList(L1);
}

#endif
