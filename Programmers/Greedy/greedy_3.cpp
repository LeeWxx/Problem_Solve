#include <string>
#include <vector>
#include <iostream>

using namespace std;

int eliminate(string number, int idx, int k)
{
    pair<int, int> max_elem = make_pair(-1, 0);
    for(int i=0; i<=k; i++)
    {
        if(max_elem.first >= number[idx + i]-'0')
            continue;
        
        max_elem = make_pair(number[idx + i]-'0', idx + i);
    }
    
    return max_elem.second - idx;
}

string solution(string number, int k) {
    string answer = "";

    int repeat = 0;

    while(k > 0)
    {
        if(repeat + k >= number.size() )
        {
            number.erase(number.end() - k, number.end());
            break;
        }
            
        int erase_cnt = eliminate(number, repeat, k);
        k -= erase_cnt;
        number.erase(number.begin() + repeat, number.begin() + repeat + erase_cnt);
        repeat++;

    }
    
    answer = number;
    return answer;
}

