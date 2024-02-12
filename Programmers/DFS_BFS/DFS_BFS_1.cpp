#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> input_vec;
int target_num;
int cnt = 0;

void go(int idx, int n)
{
    if(idx == input_vec.size())
    {
        if(target_num == n)
            cnt++;
        
        return;
    }
    go(idx+1, n+input_vec[idx]);
    go(idx+1, n-input_vec[idx]);
}

int solution(vector<int> numbers, int target) {
    target_num = target;
    input_vec = numbers;
    
    go(0, 0);
    
    int answer = cnt;
    
    return answer;
}