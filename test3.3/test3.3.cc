// #include <stdio.h>
// #include <string.h>
// #include <stack>
// #include <string>
// using namespace std;

//     void eval(stack<int>& nums,stack<char>& op)
//     {
//         int b = nums.top(); nums.pop();
//         int a = nums.top(); nums.pop();
//         if(op.top() == '+')
//             nums.push(a + b);
//         else
//             nums.push(a-b);
//         op.pop();
//     }
//     int calculate(string s) {
//         stack<int> nums;
//         stack<char> op;
//         for(int i = 0; i < s.size(); i++)
//         {
//             if(isdigit(s[i]))
//             {
//                 int n = 0,j = i;
//                 while(j < s.size() && isdigit(s[j]))
//                 {
//                     n = n*10 + (s[j] - '0');
//                     j++;
//                 }
//                 nums.push(n);
//                 i = j-1;
//             }
//             else if(s[i] == '(')
//                 op.push('(');
//             else if(s[i] == ')')
//             {
//                 while(op.top() != '(')
//                 {
//                     eval(nums,op);
//                 }
//                 op.pop();
//             }
//             else if(s[i] == ' ');
//             else
//             {
//                 if(s[i] == '-')
//                 {
//                     int k = i-1;
//                     while(k >= 0 && s[k] == ' ')
//                         k--;
//                     if(k < 0 || s[k] == '(')
//                     {
//                         int n = 0,j = i+1;
//                         while(j < s.size() && isdigit(s[j]))
//                         {
//                             n = n*10 + (s[j] - '0');
//                             j++;
//                         }
//                         nums.push(n*-1);
//                         i = j-1;
//                         continue;
//                     }
//                 }
//                 while(!op.empty() && op.top() != '(')
//                 {
//                     eval(nums,op);
//                 }
//                 op.push(s[i]);
//             }
//         }
//         while(!op.empty())
//         {
//             eval(nums,op);
//         }
//         return nums.top();
//     }

// int main()
// {
//     calculate("(1+(4+5+2)-3)+(6+8)");
//     return 0;
// }

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<char,int> s= {{'1',1}, {'2',2}};
    cout << s['('] << endl;
    return 0;
}