#include "seqList.h"

int main()
{
    cout << "1.第 i 个位置插入" << endl;
    cout << "2.第 i 个位置删除" << endl;
    cout << "3.插入保持递增" << endl;
    cout << "4.奇数偶数分离" << endl;
    cout << "5.A∩B" << endl;
    cout << "6.删除重复元素" << endl;
    int n = 0;
    cout << "选择你的功能" << endl;
    cin >> n;

    switch (n)
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
    default:
        cout << "error" << endl;
        break;
    }

    return 0;
}