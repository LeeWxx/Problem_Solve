#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> students(n, 1);

    for(int i=0; i<lost.size(); i++)
    {
        students[lost[i]-1]--;
    }
    
    for(int i=0; i<reserve.size(); i++)
    {
        students[reserve[i]-1]++;
    }
    
    int cnt = n;
    
    for(int i=0; i<students.size(); i++)
    {        
        if(students[i] == 0)
        {
            bool is_borrow = false;
            
            if(i > 0 && students[i-1] == 2)
            {
                is_borrow = true;
                students[i-1] = 1;
            }
            
            if(i < n-1 && !is_borrow && students[i+1] == 2 )
            {
                is_borrow = true;
                students[i+1] = 1;
            }
            
            if(!is_borrow)
                cnt--;
        }
    }
    
    return cnt;
}