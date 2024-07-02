#include "stack.h"

using namespace std;

//将数字栈顶两个元素进行运算
void eval(int nums[],int* top,char op)
{
    int b = nums[(*top)--];
    int a = nums[(*top)--];
    if(op == '+')
    {
        nums[++*top] = a+b;
    }
    else if(op == '-')
    {
        nums[++*top] = a-b;
    }
    else if(op == '*')
    {
        nums[++*top] = a*b;
    }
    else if(op == '/')
    {
        nums[++*top] = a/b;
    }
    else
    {
        cout << "op error" << endl;
    }
}
//中缀表达式求值
int infix(string s)
{
    stack op;
    int nums[100];
    int top = -1;
    for(int i = 0; i < s.size(); i++)
    {
        if(isdigit(s[i]))
        {
            int n = 0;
            while(i < s.size() && isdigit(s[i]))
            {
                n = (s[i] - '0') + n*10;
                i++;
            }
            i--;
            nums[++top] = n;
        }
        else
        {
            if(s[i] == '(') op.push(s[i]);
            else if(s[i] == ')')
            {
                char opt;
                op.pop(&opt);
                while(opt != '(')
                {
                    eval(nums,&top,opt);
                    op.pop(&opt);
                }
            }
            else if(!op.isempty()) //如果遇到的是运算符，且符号栈里有符号
            {
                char opt;
                opt = op.gettop();
                //如果符号栈里存的符号优先级要高于现在的符号，就计算栈
                while(!op.isempty() && (opt == '*' || opt == '/' || \
                (opt == '+' && (s[i] == '+' || s[i] == '-')) || \
                (opt == '-' && (s[i] == '+' || s[i] == '-')) ) )
                {
                    op.pop(&opt);
                    eval(nums,&top,opt);
                    opt = op.gettop();
                }
                op.push(s[i]);
            }
            else //如果遇到的是运算符，且符号栈里没有符号
            {
                op.push(s[i]);
            }
        }
        
    }
    while(!op.isempty())
    {
        char opt;
        op.pop(&opt);
        eval(nums,&top,opt);
    }
    return nums[top];
}
//后缀表达式求值
int postfix(string s)
{
    int nums[100];
    int top = -1;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ') ;
        else if(isdigit(s[i]))
        {
            int n = 0;
            while(i < s.size() && isdigit(s[i]))
            {
                n = (s[i] - '0') + n*10;
                i++;
            }
            i--;
            nums[++top] = n;
        }
        else
        {
            eval(nums,&top,s[i]);
        }
    }
    return nums[top];
}
void test_infix()
{
    cout << "请输入中缀表达式>:"; 
    string s;
    getline(cin,s);
    int res = infix(s);
    cout << "结果是：" << res << endl;
}
void test_postfix()
{
    cout << "请输入后缀表达式>:";//以空格为分隔符
    string s;
    getline(cin,s);
    int res = postfix(s);
    cout << "结果是：" << res << endl;
}
int main()
{
    test_infix();
    test_postfix();
    return 0;
}