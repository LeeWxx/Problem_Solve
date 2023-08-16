#include <iostream>

using namespace std;

const int MAX_INPUT = 15;
bool right_up_diagonal[2 * (MAX_INPUT-1) + 1];
bool left_up_diagonal[2 * (MAX_INPUT-1) + 1];
bool vertical[MAX_INPUT];
bool horizontal[MAX_INPUT];

bool check(int N,int y, int x)
{
	if(vertical[y] || horizontal[x])
		return false;
		
	if(right_up_diagonal[x+y])
		return false;
		
	int pos;
	
	if(x < N)
		pos = (N - x) + y;
	else
		pos = (x - N) + y;
		
	if(left_up_diagonal[pos])
		return false;
	
	return true;
}

void change(int N, int y, int x, bool val)
{
	vertical[y] = val;
	horizontal[x] = val;
	right_up_diagonal[y+x] = val;
		
	int pos;
	if(x < N)
		pos = (N - x) + y;
	else
		pos = (x - N) + y;
		
	left_up_diagonal[pos] = val;
}


void go(int idx, int N, int& cnt)
{
	if(idx == N)
	{
		cnt++;
		return;
	}
	
	for(int i=0; i<N; i++)
	{
		if(!check(N, idx, i))
			continue;
		
		change(N, idx, i, true);
		go(idx+1, N, cnt);
		change(N, idx, i, false);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N; 
	
	int result(0);
	go(0, N, result);
	cout << result << endl;
	
}