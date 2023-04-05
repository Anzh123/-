#ifndef _seqList_h_
#define _seqList_h_

#include <iostream>

using namespace std;

#define Max 100

struct List
{

    int data[Max];
    int ListLen;
};

void InitseqList(List *&L)
{
    L = new List;
    L->ListLen = 0;
}
void Inputdata(List *L)
{
    cout << "输入数据长度" << endl;
    int n;
    cin >> n;
    if(n > Max){
        cout << "表满" << endl;
        return ;
    }
    else{
        cout << "输入数据" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> L->data[i];
            L->ListLen++;
        }
    }
}
bool Listempty(List *L)
{

    if (L->ListLen == 0)
    {

        return true;
    }

    else
    {

        return false;
    }
}

bool Listfull(List *L)
{

    if (L->ListLen == Max - 1)
    {

        return true;
    }

    else
    {

        return false;
    }
}

void Outputdata(List *L)
{
    if (Listempty(L))
    {
        cout << "表空" << endl;
    }
    else
    {
        for (int i = 0; i < L->ListLen; i++)
        {

            cout << L->data[i] << " ";
        }
        cout << endl;
    }
}

// 插入元素
void Insertdata(List *L, int i, int x)
{

    if (i > L->ListLen + 1 || i < 1)
    {
        cout << "索引错误" << endl;
        return;
    }
    if (Listfull(L))
    {
        cout << "full" << endl;
        return;
    }

    for (int j = L->ListLen - 1; j >= i - 1; j--)
    {

        L->data[j + 1] = L->data[j];
    }

    L->data[i - 1] = x;

    L->ListLen++;
    cout << "插入后 " << endl;
    Outputdata(L);
}

// 删除元素
void Deletedata(List *L, int i)
{
    if (Listempty(L))
    {
        cout << " empty" << endl;
        return;
    }
    if (i < 1 || i > L->ListLen)
    {
        cout << "error" << endl;
        return;
    }

    for (int j = i; j <= L->ListLen - 1; j++)
    {
        L->data[j - 1] = L->data[j];
    }
    L->ListLen--;
    cout << "删除后" << endl;
    Outputdata(L);
}

// 递增顺序表的插入保持递增
void Upinsert(List *L, int n)
{
    L->ListLen++;
    L->data[L->ListLen - 1] = n; // 把插入的数放在顺序表的末尾
    for (int i = L->ListLen - 1; i > 0; i--)
    {
        if (L->data[i] >= L->data[i - 1]) // 如果插入的数比之前的都大，则满足递增要求退出
        {
            break;
        }
        else // 插入的数比相邻之前的数小，则互换位置
        {
            int temp;
            temp = L->data[i];
            L->data[i] = L->data[i - 1];
            L->data[i - 1] = temp;
        }
    }
    cout << "插入后" << endl;
    Outputdata(L);
}

// 顺序表元素的奇数偶数分类
void classify(List *L, List *L1, List *L2)
{

    for (int i = 0; i < L->ListLen; i++)
    {

        if (L->data[i] % 2)
        {

            L1->data[L1->ListLen] = L->data[i];

            L1->ListLen++;
        }

        else
        {

            L2->data[L2->ListLen] = L->data[i];

            L2->ListLen++;
        }
    }
    cout <<"原表" << endl;
    Outputdata(L);
    cout << "奇数表" << endl;
    Outputdata(L1);
    cout << "偶数表" << endl;
    Outputdata(L2);
}

// 求 A ∩ B
void A_B(List *L, List *L1, List *L2)
{

    int i = 0, j = 0, k = 0;
    while (i < L1->ListLen && j < L2->ListLen) // 减少遍历次数，只要有一个表遍历结束则结束
    {
        if (L1->data[i] == L2->data[j])
        {
            L->data[k] = L1->data[i];
            i++;
            j++;
            k++;
        }
        else if (L1->data[i] > L2->data[j])
        {
            j++;
        }
        else if (L1->data[i] < L2->data[j])
        {
            i++;
        }
    }

    L->ListLen = k;
}

// 删除递增有序数列的重复元素
void Deleterepeat(List *L)
{

    for (int i = L->ListLen - 1; i > 0; i--)
    {

        if (L->data[i] == L->data[i - 1])
        {

            for (int j = i - 1; j < L->ListLen - 1; j++)
            {

                L->data[j] = L->data[j + 1];
            }

            L->ListLen--;
        }
    }
    cout << "删重后" << endl;
    Outputdata(L);
}

void test01()
{
    List *L;
    InitseqList(L);
    Inputdata(L);
    int i;
    int x;
    cout << "插入位置和数据" << endl;
    cin >> i >> x;
    Insertdata(L, i, x);
}

void test02()
{

    List *L;
    InitseqList(L);
    Inputdata(L);
    int i;
    cout << "删除位置" << endl;
    cin >> i;
    Deletedata(L, i);
}

void test03()
{
    List *L;
    InitseqList(L);
    Inputdata(L);
    int x;
    cout << "插入数据" << endl;
    cin >> x;
    Upinsert(L, x);
}

void test04()
{
    List *L;
    List *L1;
    List *L2;
    InitseqList(L);
    InitseqList(L1);
    InitseqList(L2);
    Inputdata(L);
    classify(L, L1, L2);
}

void test05()
{

    List *L;
    List *L1;
    List *L2;
    InitseqList(L);
    InitseqList(L1);
    InitseqList(L2);
    cout << "输入第一组数据" << endl;
    Inputdata(L1);
    cout << "输入第二组数据" << endl;
    Inputdata(L2);
    A_B(L, L1, L2);
    Outputdata(L);
}

void test06()
{
    List *L;
    InitseqList(L);
    Inputdata(L);
    Deleterepeat(L);
}

#endif