#include<iostream>
#include<string>
#include"Stack.h"
using namespace std;

bool isValid(const std::string& str){
    //����charջ����
    Stack stack(4);
    for(char ch : str){
        //(������)������Ҫ�����ջ
        if(ch == '{' || ch == '(' || ch == '[')
            stack.Push(ch);
        else{
            //��ջ�������ݴ�ʱ����ȡջ��Ԫ��
            //���˴�������false����Top������assert���Իᱨ��,���³������
            if(stack.Empty())
                return false;
            char topCh = stack.Top();
            //ȡ��֮���м�Ҫ��ջ��Ԫ��(������)ȡ��,�൱��ƥ������
            stack.Pop();
            if((ch == '}' && topCh == '{') || (ch == ']' && topCh == '[') || (ch == ')' && topCh == '(') )
                continue;
            else
                return false;
        }
    }

    //ѭ������֮�� ջ�п��ܻ�����δƥ��������� �����Ҫ�ж�ջ�Ƿ�Ϊ��
    return stack.Empty();
}

int main(){
    cout << "��������ƥ����԰�����" << endl;
    string str;
    cin >> str;
    if(isValid(str))
        cout << "ƥ����Ч" << endl;
    else
        cout << "ƥ��ʧ��" << endl;
    return 0;
}