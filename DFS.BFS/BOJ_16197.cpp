#include <iostream>

using namespace std;

int xx[10] = {0, };

enum Direction
{
	UP=1,
	DOWN=2,
	LEFT=3,
	RIGHT=4
};

class Board
{
	const static int MAXIMUM_MOVE_COUNT = 10;
	
	int board_height;
	int board_width;
	
	char board[20][20];
	
	Direction direction_arr[MAXIMUM_MOVE_COUNT];
	
	pair<int, int> a_pos;
	pair<int, int> b_pos;
	
	int answer = MAXIMUM_MOVE_COUNT + 1;
	
public:
	void appendMove(int idx, int direction)
	{
		direction_arr[idx] = static_cast<Direction>(direction);
	}
	
	int getMaxMove()
	{
		return MAXIMUM_MOVE_COUNT;
	}
	
	int getAnser()
	{
		if(answer == MAXIMUM_MOVE_COUNT + 1)
			return -1;
		
		return answer;
	}
	
	void setBoard(int N, int M)
	{
		board_height = N;
		board_width = M;
		
		bool is_first_set = false;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				char ch;
				cin >> ch;
				board[i][j] = ch;
				
				if(ch == 'o')
				{
					if(is_first_set)
						a_pos = make_pair(i,j);
					else{
						b_pos = make_pair(i,j);
						is_first_set = true;
					}
				}
			}
		}
	}
	
	void solve()
	{
		int a_x = a_pos.second;
		int a_y = a_pos.first;
		
		int b_x = b_pos.second;
		int b_y = b_pos.first;
		
		for(int i=0; i<MAXIMUM_MOVE_COUNT; i++)
		{
			bool result_a;
			bool result_b;
			switch(direction_arr[i])
			{
				case Direction::UP:
					result_a = up(a_y, a_x);
					result_b = up(b_y, b_x);
					break;
				case Direction::DOWN:
					result_a =down(a_y, a_x);
					result_b =down(b_y, b_x);
					break;
				case Direction::LEFT:
					result_a =left(a_y, a_x);
					result_b =left(b_y, b_x);
					break;
				case Direction::RIGHT:
					result_a =right(a_y, a_x);
					result_b =right(b_y, b_x);
				 	break;
			}
			
			if(!result_a && !result_b)
				return;
			
			else if(!result_a || !result_b)
			{
				answer = min(answer, i+1);
				return;
			}
		}
	}
	
	bool up(int& y, int& x)
	{
		if(y-1 < 0)
			return false;
		
		
		if(board[y-1][x] != '#')
			y--;
		
		return true;
	}
	
	bool down(int& y, int& x)
	{
		if(y+1 >= board_height)
			return false;
		
		if(board[y+1][x] != '#')
			y++;
		
		return true;
	}
	
	bool right(int& y, int& x)
	{
		if(x+1 >= board_width)
			return false;
		
		if(board[y][x+1] != '#')
			x++;
		
		return true;
	}
	
	bool left(int& y, int& x)
	{
		if(x-1 < 0)
			return false;
		
		if(board[y][x-1] != '#')
			x--;
		
		return true;
	}
};

void go(int idx, Board& board)
{
	if(idx == board.getMaxMove())
	{
		board.solve();
		return;
	}
	
	for(int i=1; i<=4; i++)
	{
		board.appendMove(idx, i);
		go(idx+1, board);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M;
	
	Board* board = new Board();
	board->setBoard(N, M);
	
	go(0, *board);
	
	cout << board->getAnser() << endl;
}