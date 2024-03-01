#include <string>
#include <vector>
#include <iostream>

using namespace std;

const char VOWELS[5] = {'A', 'E', 'I', 'O', 'U'};

string target;
int answer = 0;
int cnt = -1;

void dfs(string word)
{
    cnt++;
    
    if(target == word)
    {
        answer = cnt;
        return;
    }
    
    if(word.size() >= 5)
        return;
    
    for(int i=0; i<5; i++)
    {
        dfs(word+VOWELS[i]);
    }
}

int solution(string word) {
    target = word;
    dfs("");
    return answer;
}