#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int ticket_cnt;
map<string, vector<pair<string, bool>>> ticket_map; 
vector<string> path;

bool dfs(string start, int cnt)
{
    if(cnt == ticket_cnt)
    {
        path.push_back(start);
        return true;
    }
    
    for(int i=0; i<ticket_map[start].size(); i++)
    {
        if(ticket_map[start][i].second)
            continue;
        
        ticket_map[start][i].second = true;
        
        if(dfs(ticket_map[start][i].first, cnt+1))
        {
            path.push_back(start);
            return true;
        }
        
        ticket_map[start][i].second = false;
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end());
    
    ticket_cnt = tickets.size();
    for(int i=0; i<tickets.size(); i++)
    {
        // if(ticket_map.count(tickets[i][0]))
        //     ticket_map[tickets[i][0]] = vector<pstring, bool>());
        
        ticket_map[tickets[i][0]].push_back(make_pair(tickets[i][1], false));
    }

                                            
    dfs("ICN", 0);
    
    reverse(path.begin(), path.end());
    answer = path;
    return answer;
}