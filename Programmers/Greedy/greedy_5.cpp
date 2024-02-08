#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(vector<int> l, vector<int> r)
{
    if(l[1] < r[1])
        return true;
    else
        return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), comp);
    
    int cnt = 1;
    int last = routes[0][1];
    
    for(int i=1; i<routes.size(); i++)
    {
        if(routes[i][0] > last)
        {
            cnt++;
            last = routes[i][1];
        }
    }
    
    answer = cnt;
    
    return answer;
}