#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int l, int r)
{
    string left = to_string(l);
    string right = to_string(r);
    
    if(left + right > right + left)
        return true;
    else 
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), comp);
    
    bool is_zero = true;
    
    for(int i=0; i<numbers.size(); i++)
    {
        if(is_zero && numbers[i] != 0)
            is_zero = false;
            
        answer += to_string(numbers[i]);
    }
    
    if(is_zero)
        return "0";
    
    return answer;
}