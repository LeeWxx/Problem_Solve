#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_INPUT = 9999;
int dist[MAX_INPUT + 1];
bool isPrime[MAX_INPUT + 1];

void setPrime()
{
	//먼저 모든 배열을 true로 초기화
	for (int i = 0; i <= MAX_INPUT; i++) {
		isPrime[i] = true;
	}
 
 
	for (int i = 2; i <= MAX_INPUT; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j <= MAX_INPUT; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int getNum(int* num_arr)
{
	return *num_arr * 1000 + *(num_arr+1) * 100 + *(num_arr+2) * 10 + *(num_arr+3);
}

int dfs(int* start, int* end)
{
	memset(dist, -1, sizeof(dist));
	
	int end_num = getNum(end);
	int start_num = getNum(start);
	
	if(end_num == start_num)
		return 0;
		
	queue<int*> que;
	que.push(start);
	dist[start_num] = 0;
	
	while(!que.empty())
	{
		int* num_arr = que.front();
		int num = getNum(num_arr);
		
		que.pop();
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<10; j++)
			{
				if(i == 0 && j == 0)
					continue;
				
				if(i == 3 && j % 2 ==0)
					continue;
				
				int next_num = num;
				int* next_arr = new int[4];
				
				int divisor = 1000;
				
				for(int i=0; i<4; i++)
				{
					int k = next_num / divisor;
					next_arr[i] = k;
					next_num -= k * divisor;
					divisor /= 10;
				}
				
				next_arr[i] = j;
				
				next_num = getNum(next_arr);
				
				if(!isPrime[next_num])
					continue;
				
				if(dist[next_num] != -1)
					continue;

				que.push(next_arr);
				
				dist[next_num] = dist[num] + 1;
				
				if(next_num == end_num)
				{
					return dist[next_num];
				}
			}
		}
	}
		
	
	return 0;
}


int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; 
	cin >> T;
	
	setPrime();
	
	while(T--)
	{
		int start[4];
		int end[4];
		
		string start_str;
		string end_str;
		
		cin >> start_str;
		cin >> end_str;

		for(int i=0; i<4; i++)
		{
			start[i] = start_str.at(i) - '0';
			end[i] = end_str.at(i) - '0';
		}
		
		cout << dfs(start, end) << endl;
		
	}
	
	
	
 	return 0;
}