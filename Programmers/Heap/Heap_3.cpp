#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations) {
    unordered_map<int, int> u_map; //값, 개수

    vector<int> answer;
   
    priority_queue<int, vector<int>> max_pq;
    priority_queue<int, vector<int>, greater<>> min_pq;
    int cnt = 0;
    
    for(int i=0; i<operations.size(); i++)
    {
        int x = stoi(operations[i].substr(2, operations[i].size()-2));
        
        if(operations[i][0] == 'I')
        {
            max_pq.push(x);
            min_pq.push(x);
            u_map[x]++;
            cnt++;
        }
        else
        {
            if(cnt == 0)
                continue;
            
            cnt--;
            if(x == 1){u_map[max_pq.top()]--; max_pq.pop();}
            else if(x == -1){u_map[min_pq.top()]--; min_pq.pop();}
        }
    }
    
    if(cnt == 0)
    {
        for(int i=0; i<2; i++)
        {
            answer.push_back(0);
        }
        
        return answer;
    }
    
    while(!max_pq.empty())
    {
        int x = max_pq.top();
        cout << x << ": " << u_map[x] << endl;
        if(u_map[x] < 1)
        {
            max_pq.pop();
            continue;   
        }
        
        answer.push_back(x);
        break;
    }
    
    while(!min_pq.empty())
    {
        int x = min_pq.top();
        if(u_map[x] < 1)
        {
            min_pq.pop();
            continue;   
        }
        
        answer.push_back(x);
        break;
    }
    
    return answer;
}