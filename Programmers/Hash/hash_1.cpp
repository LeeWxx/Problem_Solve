#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    
    int size = nums.size();
    
    for(int i=0; i<size; i++)
    {
        s.insert(nums[i]);
    }
    
    int answer = s.size();
    
    if(answer > size / 2)
        answer = size / 2;
    
    return answer;
}