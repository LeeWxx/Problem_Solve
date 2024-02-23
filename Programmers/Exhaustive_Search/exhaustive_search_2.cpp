#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> first = {1,2,3,4,5};
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> count = {0, 0, 0};
    
    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i] == first[i % first.size()])
            count[0]++;
        
        if(answers[i] == second[i % second.size()])
            count[1]++;
        
        if(answers[i] == third[i % third.size()])
            count[2]++;
        
    }
        
    int max_count = *max_element(count.begin(), count.end());
    
    cout << max_count << endl;
    
    for(int i=0; i<count.size(); i++)
    {
        if(count[i] == max_count)
            answer.push_back(i+1);
    }
    
    return answer;
}