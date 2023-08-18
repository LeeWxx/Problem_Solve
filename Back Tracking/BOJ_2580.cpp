#include <iostream>
#include <vector>

using namespace std;

const int LENGTH = 9;
bool vertical[LENGTH][LENGTH];
bool horizontal[LENGTH][LENGTH];
bool box[LENGTH][LENGTH];

int board[LENGTH][LENGTH];
vector<int> empty_pos;

bool is_end = false;

bool check(int x, int y, int num)
{
	int box_idx = (x / 3) + ((y / 3)) * 3;
	if(vertical[x][num] || horizontal[y][num] || box[box_idx][num])
		return false;
	
	return true;
}

void OnOff(int x, int y, int num, bool val)
{
	int box_idx = (x / 3) + ((y / 3)) * 3;
	
	vertical[x][num] = val;
	horizontal[y][num] = val; 
	box[box_idx][num] = val;
	
	if(val == true)
		board[y][x] = num;
}

void print()
{
	for(int i=0; i<LENGTH; i++)
	{
		for(int j=0; j<LENGTH; j++)
		{
			cout << board[i][j] << " ";
		}
		
		if(i != LENGTH-1)
			cout << "\n";
	}
	
	is_end = true;
}

void go(int idx, int N)
{
	if(is_end)
		return;
	
	if(idx == N)
	{
		print();
		return;
	}
	
	int y_pos = empty_pos[idx] / LENGTH;
	int x_pos = empty_pos[idx] % LENGTH;
	
	for(int i=1; i<=LENGTH; i++)
	{
		if(!check(x_pos, y_pos, i))
			continue;
		
		OnOff(x_pos, y_pos, i, true);
		go(idx+1, N);
		OnOff(x_pos, y_pos, i, false);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int i=0; i<LENGTH; i++)
	{
		for(int j=0; j<LENGTH; j++)
		{
			int x;
			cin >> x;
			
			if(x != 0)
				OnOff(j, i, x, true);
			else
			{
				empty_pos.push_back(i * LENGTH + j);
			}
		}
	}
	
	go(0, empty_pos.size());
}