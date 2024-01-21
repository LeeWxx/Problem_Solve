#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int needHot;
    priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());

    while(pq.top()<K) {
        if(pq.size()==1) return answer = -1;
        needHot=pq.top(); pq.pop();
        pq.push(needHot+pq.top()*2);
        pq.pop(); answer++;
    }

    return answer;
}