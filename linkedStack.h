#ifndef _linked_h_
#define _linked_h_
#include <iostream>
#include <string>
using namespace std;
struct lstack
{
    char data;
    lstack *next;
};
void initlstack(lstack *&top)
{   
    top = new lstack;
    top->next = NULL;
}
void push(lstack *top, char x)
{
    lstack *t = new lstack;

    if ( top ->next == NULL ){
        t->data = x;
        t->next = NULL;
        top->next = t;
    } 
    else {
        t->data = x ;
        t->next = top->next;
        top->next = t;
    }
}
char pop(lstack *top)
{
    lstack *t;
    char x;
    if (top->next == NULL)
    {
        cout <<"栈空"<< endl;
        return '!';
    }
    else
    {
        t = top->next;
        x = t->data;
        top->next = t->next;
        delete t;
        return x;
    }
}
bool stackempty(lstack *top){
    if (top->next == NULL){
        return true;
    }
    else {
        return false;
    }
}
int changetoNumber (string x)
{
    int num = 0;
    for (int i = 0; i < x.size(); i++)
    {
        num = num * 10 + x[i] - '0';
    }
    return num;
}
void change(lstack *top, string x, int n)
{
    int num = changetoNumber(x);
    while (num != 0)
    {
        int node = num % n;
        if (node >= 10)
        {
            char m = node - 10 + 'A';
            push(top, m);
        }
        else
        {
            char n = node + '0';
            push(top, n);
        }
        num = num / n;
    }

    cout<<changetoNumber(x)<< "转化为" << n << "进制为" << endl;

    while (!stackempty(top))
    {
        char k = pop(top);
        cout << k;
    }
}
void ltest01()
{
    lstack *top;
    initlstack(top);
    string x;
    int n;
    cout << "输入十进制数" << endl;
    cin >> x;
    cout << "进制" << endl;
    cin >> n;
    change(top,x,n);
}

bool bracketMatch2(lstack *top,string str)
{
    int len = str.length(); // 获得数学表达式的长度
    bool tag = true;
    bool result;
    int i = 0;
    char x;
    while (i < len && tag == true)
    {
        switch (str[i])
        {
        // 所有左括号入栈
        case '(':
        case '[':
        case '{':
            push(top,str[i]);
            break;
        case ')':
            // 扫描到右括号时，如果当前栈空，右括号多于左括号
            if (stackempty(top))
            {
                tag = false;
                result = false;
                break;
            }
            // 得到栈顶元素，并出栈
            x = pop(top);
            if (x == '(')
            {
                break;
            }
            else
            {
                tag = false;
                result = false;
                break;
            }
        case ']':
            if (stackempty(top))
            {
                tag = false;
                result = false;
                break;
            }
            // 得到栈顶元素，并出栈
            x = pop(top);
            if (x == '[')
            {
                break;
            }
            else
            {
                tag = false;
                result = false;
                break;
            }
        case '}':
            if (stackempty(top))
            {
                tag = false;
                result = false;
                break;
            }
            // 得到栈顶元素，并出栈
            x = pop(top);
            if (x == '{')
            {
                break;
            }
            else
            {
                tag = false;
                result = false;
                break;
            }
        default:
            break;
        }
        i++;
    }
    if (stackempty(top) && tag == true)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    return result;
}

void ltest02()
{
    lstack *top;
    initlstack(top);
    string str;
    cout << "Input Str" << endl;
    cin >> str;
    if(bracketMatch2(top,str)){
        cout << "表达式正确" << endl;
    }
    else {
        cout << "表达式错误" << endl;
    }
}


void Llegaloutput(vector<char> kind)
{
    lstack *top;
    initlstack(top);
    char x = '1';
    char y;

    vector<char>::iterator it;
    for (it = kind.begin(); it != kind.end(); it++)
    {
        if (*it == '1')
        {
            push(top, x);
            x = char(x + 1);
        }
        if (*it == '0')
        {
            y = pop(top);
            cout << y << " ";
        }
    }
    cout << endl;
}

void Loutputall(vector<char> kind, int count[], int n)
{
    if (count[1] >= 1) // 情况（1），剩余数列中还有1
    {
        kind.push_back('1');
        count[1]--;
        Loutputall(kind, count, n); // 递归
        count[1]++;
        kind.pop_back(); // 还原到操作（1）前
    }
    if ((count[0] >= 1) && (count[0] > count[1]))
    { // 情况（2），剩余数列中还有0且0比1多
        kind.push_back('0');
        count[0]--;
        Loutputall(kind, count, n); // 递归
        count[0]++;
        kind.pop_back(); // 还原到操作（2）前
    }
    if (kind.size() == 2 * n) // 所有元素都扫描完毕，输出
    {
        Llegaloutput(kind);
    }
}

void ltest03()
{
    int n;
    cout << "please input the number:" << endl;
    cin >> n;
    int count[2] = {n, n - 1};
    vector<char> kind;
    kind.push_back('1'); // 合法序列的第一个数一定是1
    outputall(kind, count, n);
}

#endif