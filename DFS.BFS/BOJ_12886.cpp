#include <iostream>
#include <queue>

using namespace std;

const int MAX_INPUT = 500;
bool checked[3*MAX_INPUT+1][3*MAX_INPUT+1];

void bfs(int x, int y, int z)
{
	int sum = x + y + z;
	
	queue<pair<int, int>> que;
	que.push(make_pair(x,y));
	checked[x][y] = true;

	
	while(!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		
		que.pop();
		
		int _arr[3] = {x, y, sum - (x+y)};
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				if(_arr[i] < _arr[j])
				{
					int arr[3] = {x, y, sum - (x+y)};
					
					arr[i] += arr[i];
					arr[j] -= _arr[i];
					
					int a = arr[0];
					int b = arr[1];
						
					if(checked[a][b])
						continue;
					
					que.push(make_pair(a, b));
					checked[a][b] = true;
				}
			}
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int A, B, C;
	cin >> A >> B >> C;
	
	int sum = A+B+C;
	if(sum % 3 != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	
	bfs(A, B, C);
	   
	if(checked[sum / 3][sum / 3] == true)
	   cout << 1 << endl;
	else
	   cout << 0 << endl;
}