#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {

    int width = 0;
    int max_idx;
    
    for(int i=0; i<sizes.size(); i++)
    {
        if(sizes[i][0] >= sizes[i][1] && sizes[i][0] > width)
        {
            width = sizes[i][0];
            max_idx = 0;
        }
        else if(sizes[i][0] < sizes[i][1] && sizes[i][1] > width)
        {
            width = max(width, sizes[i][1]);
            max_idx = 1;
        }
    }
    
    int another_idx = 1 - max_idx;
    int height = 0;
    
    for(int i=0; i<sizes.size(); i++)
    {
        if(sizes[i][max_idx] < sizes[i][another_idx])
        {
            int temp = sizes[i][max_idx];
            sizes[i][max_idx] = sizes[i][another_idx];
            sizes[i][another_idx] = temp;
        }
        
        height = max(height, sizes[i][another_idx]);
    }

    int answer = width * height;
    return answer;
}