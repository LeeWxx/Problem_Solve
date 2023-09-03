#include <iostream>
#include <string>
using namespace std;

const int MAX_INPUT = 20;
char input_arr[MAX_INPUT][MAX_INPUT];
bool checked[26];

int xn[4] = {-1, 1, 0, 0};
int yn[4] = {0, 0, -1, 1};

void go(int y, int x, int R, int C, int cnt, int& result)
{
	if(cnt > result)
		result = cnt;
	
	char alphabet = input_arr[y][x];
	checked[alphabet-'A'] = true;
	
	for(int i=0; i<4; i++)
	{
		int next_x = x + xn[i];
		int next_y = y + yn[i];
		
		if(next_x < 0 || next_x >= C || next_y < 0 || next_y >= R)
			continue;
		
		char next_alphabet = input_arr[next_y][next_x];
		if(checked[next_alphabet-'A'])
			continue;
		
		go(next_y, next_x, R, C, cnt+1, result);
	}
	
	checked[alphabet-'A'] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int R,C;
	cin >> R >> C;
	
	for(int i=0; i<R; i++)
	{
		string s;
		cin >> s;
		for(int j=0; j<C; j++)
			input_arr[i][j] = s.at(j);
	}
	
	int result(0);
	go(0, 0, R, C, 1, result);
	
	cout << result << endl;	
}