#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

string bfs(int s, int k)
{
	set<int> _set;
	queue<pair<long long,string>> que;
	que.push(make_pair(s, ""));
	
	_set.insert(s);
	
	while(!que.empty())
	{
		long long x = que.front().first;
		string exp = que.front().second;
		
		que.pop();
		
		if(x == k)
			return exp;
		
		if(x*x <= k && _set.find(x * x) == _set.end())
		{
			_set.insert(x * x);
			que.push(make_pair(x * x, exp + "*"));
		}
		
		if(x+x <= k && _set.find(x + x) == _set.end())
		{
			_set.insert(x + x);
			que.push(make_pair(x + x, exp + "+"));
		}
		
		if(_set.find(1) == _set.end() && x != 0)
		{
			_set.insert(1);
			que.push(make_pair(1, exp + "/"));
		}
	}
	
	return "fail";
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long s, k;
	cin >> s >> k;
	
	if(s == k)
	{
		cout << 0 << endl; 
		return 0;	
	}
	
	string result = bfs(s, k);
	
	if(result == "fail")
		cout << -1 << endl;
	else
		cout << result << endl;
		
 	return 0;
}