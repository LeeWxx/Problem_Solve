#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> que;
void hanoi(int n, int x, int y) 
{
	if (n == 0) 
		return; 
	else
	{
		hanoi(n - 1, x, 6-x-y);
		que.push(make_pair(x, y));
		hanoi(n - 1, 6-x-y, y);
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	hanoi(N, 1, 3);	
	
	cout << que.size() << "\n";
	
	int size = que.size();
	
	while(!que.empty())
	{
		cout << que.front().first << " " << que.front().second << "\n";
		que.pop();
	}
}