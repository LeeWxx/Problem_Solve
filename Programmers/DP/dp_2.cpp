#include <string>
#include <vector>
#include <string.h>

using namespace std;

const int MAX_SIZE = 500;

int dp[MAX_SIZE + 1][MAX_SIZE + 1];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size();
    
    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = triangle[0][0];
    
    for(int i=1; i<height; i++)
    {
        for(int j=0; j<=i; j++)
        {
            dp[i][j] = 0;
            
            if(j != triangle[i].size()-1)
                dp[i][j] = max(dp[i-1][j] + triangle[i][j], dp[i][j]);    
            
            if(j != 0)
                dp[i][j] = max(dp[i-1][j-1] + triangle[i][j], dp[i][j]);
        }   
    }
    
    for(int i=0; i<height; i++)
        answer = max(dp[height-1][i], answer);
    
    return answer;
}