#include <iostream>
#include <queue>

using namespace std;

const int MAX_INPUT = 100000;

struct Data
{
	int left_x;
	int height;
	int right_x;
	
	 bool operator<(const Data d) const {
        return this->height < d.height;
	 }
};

Data input[MAX_INPUT+1];
Data copy_arr[MAX_INPUT+1];


bool comp(Data a, Data b)
{
	if(a.left_x < b.left_x)
		return true;
	
	else if(a.left_x == b.left_x)
	{
		if(a.height > b.height)
			return true;
	}
	
	return false;
		
}

void merge(int left, int right)
{
	int mid = (left + right) / 2;
	
	int l_idx = left;
	int r_idx = mid + 1;
	
	int copy_idx = left;
	
	while(l_idx <= mid && r_idx <= right)
	{
		if(comp(input[l_idx], input[r_idx]))
			copy_arr[copy_idx++] = input[l_idx++];
		else
			copy_arr[copy_idx++] = input[r_idx++];	
	}
	
	while(l_idx <= mid)
		copy_arr[copy_idx++] = input[l_idx++];
	
	while(r_idx <= right)
		copy_arr[copy_idx++] = input[r_idx++];
	
	for(int i=left; i<=right; i++)
		input[i] = copy_arr[i];
}

void mergeSort(int left, int right)
{
	if(left >= right)
		return;
	
	int mid = (left + right) / 2;
	
	mergeSort(left, mid);
	mergeSort(mid+1, right);
	merge(left, right);
}

void solve(int N)
{
	mergeSort(1, N);
	
	priority_queue<Data> p_que;
	
	int idx = 1;
	Data* sky_line;
	
	Data data;
	data.left_x = 0;
	data.height = 0;
	data.right_x = 0;
	
	sky_line = &data;
	
	while(idx <= N || !p_que.empty())
	{
		if(idx <= N && input[idx].left_x <= sky_line->right_x)
		{
			if(sky_line->height > input[idx].height)
				p_que.push(input[idx++]);
			else if(sky_line->height < input[idx].height)
			{
				p_que.push(*sky_line);
					
				cout << input[idx].left_x << " " << input[idx].height << " ";
				sky_line = &input[idx++];
			}
			else
			{
				if(input[idx].right_x > sky_line->right_x)
					sky_line = &input[idx];
			
				idx++;
			}
		}
		else
		{
			if(idx <= N && p_que.empty())
			{
				if(sky_line->right_x > 0)
					cout << sky_line->right_x << " " << 0 << " ";
				
				cout << input[idx].left_x << " " << input[idx].height << " ";
				sky_line = &input[idx++];		
			}
			else
			{
				if(sky_line->right_x < p_que.top().right_x)
				{
					cout << sky_line->right_x << " " <<  p_que.top().height << " ";
					
					Data data;
					data.left_x = p_que.top().left_x;
					data.height = p_que.top().height;
					data.right_x = p_que.top().right_x;
					
					sky_line = &data;
					p_que.pop();
				}
				else
				{
					p_que.pop();
				}
			}
		}
	}
	
	cout << sky_line->right_x << " " << 0 << endl;
}

void inputFunc(int N)
{
	for(int i=1; i<=N; i++)
	{
		int left_x, height, right_x;
		cin >> left_x >> height >> right_x;
		
		Data data;
		data.left_x = left_x;
		data.height = height;
		data.right_x = right_x;
		
		input[i] = data;
	}	
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	
	int N;
	cin >> N;
	
	inputFunc(N);
	solve(N);
}






