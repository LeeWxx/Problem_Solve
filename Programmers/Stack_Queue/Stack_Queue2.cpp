#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    vector<int> days;
    vector<int> answer;
    
    for(int i=0; i<speeds.size(); i++)
    {
        float day =  (100 - progresses[i]);
        float speed = speeds[i];
        
        days.push_back(ceil(day / speed));
        
    }   
    
    int now = days[0];
    answer.push_back(1);
    
   for(int i=1; i<days.size(); i++)
   {
       if(now >= days[i])
           answer[answer.size()-1]++;
       else
       {
           answer.push_back(1);
           now = days[i];
       }
   }
    return answer;
}