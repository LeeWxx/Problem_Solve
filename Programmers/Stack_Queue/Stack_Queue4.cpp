#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> que;
    vector<int> sorted;     
    
    for(int i=0; i<priorities.size(); i++)
        que.push(i);
    
    int max_val = *max_element(priorities.begin(), priorities.end()); 
    while(!que.empty())
    {
        int idx = que.front();
        que.pop();
        
        if(priorities[idx] != max_val)
            que.push(idx);
        else
        {
            priorities[idx] = 0;
            sorted.push_back(idx);
            max_val = *max_element(priorities.begin(), priorities.end()); 
        }
    }
    
    for(int i=0; sorted.size(); i++)
    {
        if(location == sorted[i])
            return i+1;
    }
    
}