#include <iostream>
#include <climits>

using namespace std;

const int MAX_N_INPUT = 11;

int input_arr[MAX_N_INPUT];
int output_op[MAX_N_INPUT-1];
int op_cnt[4] = {0, };
int checked_cnt[4] = {0, };

int getSum(int N)
{
	int sum = input_arr[0];
	for(int i=0; i<N; i++)
	{
		switch(output_op[i])
		{
			case 1:
				sum += input_arr[i+1];
				break;
			case 2:
				sum -= input_arr[i+1];
				break;
			case 3:
				sum *= input_arr[i+1];
				break;
			case 4:
				sum /= input_arr[i+1];
			 	break;
		}
	}
	return sum;
}

void go(int idx, int target_idx, int& max_val, int& min_val)
{
	if(idx == target_idx)
	{
		int sum = getSum(target_idx);
		max_val = max(max_val, sum);	
		min_val = min(min_val, sum);
		
		return;
	}
	
	for(int i=0; i<4; i++)
	{
		if(checked_cnt[i] >= op_cnt[i])
			continue;
		
		output_op[idx] = i+1;
		++checked_cnt[i];
		go(idx+1, target_idx, max_val, min_val);
		--checked_cnt[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> input_arr[i];
	
	for(int i=1; i<=4; i++)
	{
		int k;
		cin >> k;
		
		op_cnt[i-1] = k;
	}
	
	int max_output(-INT_MAX);
	int min_output(INT_MAX);
	
	go(0, N-1, max_output, min_output);
	
	cout << max_output << endl;
	cout << min_output << endl;
}