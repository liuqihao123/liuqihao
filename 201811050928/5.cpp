#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int expression_value()//一个表达式的值
{
	int term_value();
    int result=term_value();
    while(true)
    {
        char op = cin.peek();
        if(op=='+'||op=='-')
        {
            cin.get();
            int value=term_value();
            if(op=='+') result +=value;
            else result -=value;
        }
        else break;
    }
    return result;
}

int factor_value() //因子
{
    int result=0;
    char c=cin.peek();
    if(c=='(')
    {
        cin.get();
        result = expression_value();
        cin.get();
    }
    else
    {
        while(isdigit(c))
        {
            result=10*result+c-'0';
            cin.get();
            c=cin.peek();
        }
    }
    return result;
}
int term_value()
{
    int result=factor_value();
    while(true)
    {  
        char op=cin.peek();
        if(op=='*'||op=='/')
        {
            cin.get();
            int value =factor_value();
            if(op=='*')
            result *=value;
            else result /=value;
        }
        else break;
    }
    return result;
}



int main()
{
    cout<<expression_value()<<endl;
    return 0;
}