#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
vector<int> parent(MAX_N);

void Union(int a, int b)
{

    while(parent[a] != a)
        a = parent[a];
    
    while(parent[b] != b)
        b = parent[b];
    
    parent[b] = a;
}

int Find(int x)
{
    while(parent[x] != x)
        x = parent[x];
    
    return x;
}

bool isUnion(int a, int b)
{   
    return Find(a) == Find(b);
}

int solution(int n, vector<vector<int>> costs) {
    if(n == 1)
        return 0;
    
    int answer = 0;
    
    for(int i=0 ;i<n; i++) parent[i] = i;
    
    vector<vector<int>> bridges;
    
    for(int i=0; i<costs.size(); i++)
    {
        vector<int> bridge(3);
        
        bridge[0] = costs[i][2];
        bridge[1] = costs[i][0];
        bridge[2] = costs[i][1];
        
        bridges.push_back(bridge);
    }
    
    sort(bridges.begin(), bridges.end());
    
    int union_cnt = 1;
    
    for(int i=0; i<bridges.size(); i++)
    {
        if(isUnion(bridges[i][1], bridges[i][2]))
           continue; 
        
        Union(bridges[i][1], bridges[i][2]);
        union_cnt++;
        answer += bridges[i][0];
        
        if(union_cnt == n)
            break;
    }
    
    return answer;
}