#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<pair<int, int>> truck_que;
    
    int first = 0;
    int last = 0;
    int now_weight = 0;
    int truck_idx = 0;
    int sec = 0;
    
    while(truck_idx < truck_weights.size())
    {
        if(last == bridge_length)
        {
            now_weight -= truck_que.front().first;
            truck_que.pop();
            last = now_weight > 0 ? last - truck_que.front().second : 0;
        }
        
        if(weight >= now_weight + truck_weights[truck_idx])
        {
            now_weight += truck_weights[truck_idx];
            truck_que.push(make_pair(truck_weights[truck_idx], first));
            first = 0;
            
            truck_idx++;
        }
        
        first++;
        last++;
        sec++;
    }
    
    return sec + bridge_length;
}