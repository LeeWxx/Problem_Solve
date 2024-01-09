#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> l, pair<int, int> r)
{
    if(l.first == r.first)
        return l.second < r.second ? true : false;
    else if(l.first < r.first)
        return false;
    else
        return true;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> total_cnt_map;
    unordered_map<string, vector<pair<int, int>>> index_map;
    
    for(int i=0; i<genres.size(); i++)
    {
        total_cnt_map[genres[i]] += plays[i];
        index_map[genres[i]].push_back(make_pair(plays[i],i));
    }
    
    vector<pair<int, string>> total_cnt_vec;
    for(auto iter : total_cnt_map)
    {
        total_cnt_vec.push_back(make_pair(iter.second, iter.first));
        sort(index_map[iter.first].begin(), index_map[iter.first].end(), comp);
    }
    
    
    
    sort(total_cnt_vec.begin(), total_cnt_vec.end(), greater<>());
    
    for(int i=0; i<total_cnt_vec.size(); i++)
    {
        string genre = total_cnt_vec[i].second;
        
        int size = min((int)(index_map[genre].size()), 2);
        
        for(int i=0; i<size; i++)
        {
            answer.push_back(index_map[genre][i].second);
        }
    }
    
    return answer;
}