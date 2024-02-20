#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int MAX_WORDS_SIZE = 50;

bool checked[MAX_WORDS_SIZE];

bool validate(string begin, string target)
{
    int cnt = 0;
    for(int i=0; i<begin.size(); i++)
    {
        if(begin[i] != target[i])
            cnt++;
    }
    
    if(cnt == 1)
        return true;
    
    return false;
}

int bfs(string begin, string target, vector<string> words)
{
    queue<pair<string, int>> que;
    que.push(make_pair(begin, 0));
    
    while(!que.empty())
    {
        string s = que.front().first;
        int pre_dist = que.front().second;
        
        que.pop();
        
        for(int i=0; i<words.size(); i++)
        {
            if(checked[i])
                continue;
            
            if(!validate(s, words[i]))
                continue;
            
            if(words[i] == target)
                return pre_dist+1;
            
            que.push(make_pair(words[i], pre_dist+1));
            checked[i] = true;
        }
        
    }
    
    return 0;

}

int solution(string begin, string target, vector<string> words) {
    int answer;
    answer = bfs(begin, target, words);
    return answer;
}