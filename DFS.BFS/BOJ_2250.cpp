#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX_N_INPUT = 10000;

struct Node
{
	int left;
	int right;
};

Node node_arr[MAX_N_INPUT+1];
vector<int> board[MAX_N_INPUT+1];

int max_depth(0);

void inorder(int node_idx, int& cnt, int depth)
{
	if(node_idx == -1)
		return; 
	
	if(depth > max_depth)
		max_depth = depth;
	
	
	inorder(node_arr[node_idx].left, cnt, depth+1);
	board[depth].push_back(cnt++);
	inorder(node_arr[node_idx].right, cnt, depth+1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	int parent_arr[MAX_N_INPUT+1];
	for(int i=1; i<=N; i++)
	{
		int data, left, right;
		cin >> data >> left >> right;

		node_arr[data].left = left;
		node_arr[data].right = right;
		
		parent_arr[left] = data;
		parent_arr[right] = data;
	}
	
	int root;
	
	for(int i=1; i<=N; i++)
	{
		if(parent_arr[i] == 0)
			root = i;
	}
	
	int cnt(0);
	inorder(root, cnt, 1);
	
	int result(0);
	int result_depth;
	for(int i=1; i<=max_depth; i++)
	{		
		int max_val(0);
		int min_val(INT_MAX);
		
		for(int j=0; j<board[i].size(); j++)
		{
			int val = board[i].at(j);
			
			max_val = max(val, max_val);
			min_val = min(val, min_val);
		}
		
		int width = max_val - min_val + 1;
		
		if(width > result)
		{
			result = max(width, result);
			result_depth = i;
		}
	}
	
	cout << result_depth << " " << result << endl;
}