#ifndef _SeqStack_h_
#define _SeqStack_h_
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 100
struct sstack
{
    char data[MAX];
    int top;
};

void Initstack(sstack *&s)
{
    s = new sstack;
    s->top = -1;
}

bool stackempty(sstack *s)
{
    if (s->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool stackfull(sstack *s)
{
    if (s->top == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char stacktop(sstack *s)
{
    char x;
    x = '!';
    if (stackempty(s))
    {
        cout << "栈空" << endl;
    }
    else
    {
        x = s->data[s->top];
    }
    return x;
}

void push(sstack *s, char x)
{
    if (stackfull(s))
    {
        cout << "栈满" << endl;
    }
    else
    {

        s->top++;
        s->data[s->top] = x;
    }
}

char pop(sstack *s)
{
    char x;
    if (stackempty(s))
    {
        cout << "栈空" << endl;
    }
    else
    {
        x = s->data[s->top];
        s->top--;
    }
    return x;
}

int changeNumber(string x)
{
    int num = 0;
    for (int i = 0; i < x.size(); i++)
    {
        num = num * 10 + x[i] - '0';
    }
    return num; //将字符串转化为数字
}
void change(sstack *ss, string x, int n)
{

    int num = changeNumber(x);

    while (num != 0)
    {
        int node = num % n;
        if (node >= 10)
        {
            char m = node - 10 + 'A';
            push(ss, m);
        }
        else
        {
            char n = node + '0';
            push(ss, n);
        }
        num = num / n;
    }

    cout<<changeNumber(x)<< "转化为" << n << "进制为" << endl;

    while (!stackempty(ss))
    {
        char k = pop(ss);
        cout << k;
    }
}

void stest01()
{
    sstack *ss;
    Initstack(ss);
    string x;
    int n;
    cout << "输入十进制数" << endl;
    cin >> x;
    cout<< "进制" << endl;
    cin >> n;
    change(ss, x, n);
}

bool bracketMatch2(sstack *S, string str)
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
            push(S, str[i]);
            break;
        case ')':
            // 扫描到右括号时，如果当前栈空，右括号多于左括号
            if (S->top == -1)
            {
                tag = false;
                result = false;
                break;
            }
            // 得到栈顶元素，并出栈
            x = pop(S);
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
            if (S->top == -1)
            {
                tag = false;
                result = false;
                break;
            }
            // 得到栈顶元素，并出栈
            x = pop(S);
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
            if (S->top == -1)
            {
                tag = false;
                result = false;
                break;
            }
            // 得到栈顶元素，并出栈
            x = pop(S);
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
    if (S->top == -1 && tag == true)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    return result;
}

void stest02()
{
    sstack *ss;
    Initstack(ss);
    string str;
    cout << "Input Str" << endl;
    cin >> str;
    if(bracketMatch2(ss,str)){
        cout << "表达式正确" << endl;
    }
    else {
        cout << "表达式错误" << endl;
    }
}

void legaloutput(vector<char> kind)
{

    sstack *s;
    Initstack(s);
    char x = '1';
    char y;

    vector<char>::iterator it;
    for (it = kind.begin(); it != kind.end(); it++)
    {
        if (*it == '1')
        {
            push(s, x); //为1入栈
            x = char(x + 1);
        }
        if (*it == '0')
        {
            y = pop(s); //为0出栈
            cout << y << " ";
        }
    }
    cout << endl;
}

void outputall(vector<char> kind, int count[], int n)
{
    if (count[1] >= 1) // 情况（1），剩余数列中还有1
    {
        kind.push_back('1');
        count[1]--;
        outputall(kind, count, n); // 递归
        count[1]++;
        kind.pop_back(); // 还原到操作（1）前
    }
    if ((count[0] >= 1) && (count[0] > count[1]))
    { // 情况（2），剩余数列中还有0且0比1多
        kind.push_back('0');
        count[0]--;
        outputall(kind, count, n); // 递归
        count[0]++;
        kind.pop_back(); // 还原到操作（2）前
    }
    if (kind.size() == 2 * n) // 所有元素都扫描完毕，输出
    {
        legaloutput(kind);
    }
}

void stest03()
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