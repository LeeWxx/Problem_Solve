#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stack;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(')
            stack.push(s[i]);
        else
        {
            if(stack.empty())
                return false;
            stack.pop();
        }
    }
    
    if(stack.size() == 0)
        return true;
    else
        return false;
}