#include <string>
#include <vector>
#include <algorithm>
#include <iostream> 

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    sort(dungeons.begin(), dungeons.end());
    
    do
    {
        int stamina = k;
        int count = 0;
        
        for(int i=0; i<dungeons.size(); i++)
        {
            if(stamina<dungeons[i][0])
                break;
            
            stamina -= dungeons[i][1];
            count++;
        }
        
        answer = max(count, answer);
    }
    while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}