#include "SeqStack.h"
#include "linkedStack.h"

int main()
{
   cout << "1.顺序栈进制转换" << endl;
   cout << "2.顺序栈判断表达式括号" << endl;
   cout << "3.顺序栈的所有合法输出" << endl;
   cout << "4.链栈进制转换" << endl;
   cout << "5.链栈判断表达式括号" << endl;
   cout << "6.链栈的所有合法输出" << endl;

   int choice;
   cout << "你的选择是" << endl;
   cin >> choice;

   switch (choice)
   {
   case 1:
   {
      stest01();
      break;
   }
   case 2:
   {
      stest02();
      break;
   }
   case 3:
   {
      stest03();
      break;
   }
   case 4:
   {
      ltest01();
      break;
   }
   case 5:
   {
      ltest02();
      break;
   }
   case 6:
   {
      ltest03();
      break;
   }
   default:
      break;
   }

   return 0;
}
