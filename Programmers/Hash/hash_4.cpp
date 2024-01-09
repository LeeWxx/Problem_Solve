#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int total_cnt = 0;
vector<string> cartegory_vec;
vector<string> selected_vec;
unordered_map<string, int> map;

void go(int r, int depth, int now)
{
    if(depth == r)
    {
         int count = 1;
         for(int i=0; i< depth; i++)
         {
             count *= map[selected_vec[i]];
         }
        
        total_cnt += count;
        return;
    }
    
    for(int i=now; i<cartegory_vec.size(); i++)
    {
        selected_vec[depth] = cartegory_vec[i];
        go(r, depth+1, i+1);
    }
}

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    for(int i=0; i<clothes.size(); i++)
    {
        if(map.find(clothes[i][1]) == map.end())
        {
            selected_vec.push_back("");
            cartegory_vec.push_back(clothes[i][1]);
        }
        
        map[clothes[i][1]]++;
    }
    
    int cnt = 0;
    for(int i=1; i<=map.size(); i++)
    {
        go(i, 0, 0);
    }
    
    answer = total_cnt;
    return answer;
}