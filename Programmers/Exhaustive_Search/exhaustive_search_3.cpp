#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

bool isPrime(int num)
{
    if(num < 2)
        return false;

    for(int i=2; i<=sqrt(num); i++)
    {
        if(num % i == 0)
            return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    vector<int> container;
    
    sort(numbers.begin(), numbers.end());
    do
    {
        for(int i=1; i<=numbers.size(); i++)
        {
            int num = stoi(numbers.substr(0, i));
            container.push_back(num);  
        }
    }
    while(next_permutation(numbers.begin(), numbers.end()));
    
    sort(container.begin(), container.end());
    container.erase(unique(container.begin(), container.end()), container.end());

    for(int i=0; i<container.size(); i++)
    {
        if(isPrime(container[i]))
        {
            answer++;
        }
    }
    
    return answer;
}