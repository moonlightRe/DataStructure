#include<iostream>
#include<string>
#include"Stack.h"
using namespace std;

bool isValid(const std::string& str){
    //创建char栈对象
    Stack stack(4);
    for(char ch : str){
        //(左括号)若符合要求则进栈
        if(ch == '{' || ch == '(' || ch == '[')
            stack.Push(ch);
        else{
            //若栈中无数据此时不能取栈顶元素
            //若此处不返回false，在Top函数中assert断言会报错,导致程序结束
            if(stack.Empty())
                return false;
            char topCh = stack.Top();
            //取出之后切记要将栈顶元素(左括号)取出,相当于匹配消除
            stack.Pop();
            if((ch == '}' && topCh == '{') || (ch == ']' && topCh == '[') || (ch == ')' && topCh == '(') )
                continue;
            else
                return false;
        }
    }

    //循环结束之后 栈中可能还残留未匹配的左括号 因此需要判断栈是否为空
    return stack.Empty();
}

int main(){
    cout << "输入括号匹配测试案例：" << endl;
    string str;
    cin >> str;
    if(isValid(str))
        cout << "匹配有效" << endl;
    else
        cout << "匹配失败" << endl;
    return 0;
}