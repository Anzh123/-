#include "LinkedList.h"

int main()
{

    cout << "1.指定位置插入数据" << endl;
    cout << "2.指定位置删除数据" << endl;
    cout << "3.插入数据保持递增" << endl;
    cout << "4.奇数表和偶数表分离" << endl;
    cout << "5.两个链表的交集" << endl;
    cout << "6.删除链表重复元素" << endl;
    cout << "7.合并两个链表" << endl;

    int choice = 0;
    cout << "你的选择是" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        test01();
        break;
    }
    case 2:
    {
        test02();
        break;
    }
    case 3:
    {
        test03();
        break;
    }
    case 4:
    {
        test04();
        break;
    }
    case 5:
    {
        test05();
        break;
    }
    case 6:
    {
        test06();
        break;
    }
    case 7:
    {
        test07();
    }
    default:
        break;
    }


    return 0;
}