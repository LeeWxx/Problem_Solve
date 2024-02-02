#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int side_move_cnt = name.size()-1;
        
    for(int i=0; i<name.size(); i++)
    {
        //위, 아래로 조이스틱 조작
        if(name[i] != 'A')
             answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        //왼쪽, 오른쪽으로 조이스틱 조작
        int idx = i+1;
        while(name[idx] == 'A') idx++;
        
        int len = name.size() - idx;
        side_move_cnt = 
            min(side_move_cnt, i + len + min(i, len));
    }
    
    return answer + side_move_cnt;
}