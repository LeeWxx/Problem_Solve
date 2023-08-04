#include <iostream>
#include <climits>

using namespace std;

const int MAX_N_INPUT = 11;

int input_arr[MAX_N_INPUT];
int op_arr[MAX_N_INPUT-1];

bool next_permutaion(int* arr, int N)
{	
	int first_idx(-1);
	
	for(int i=N-2; i>=0; i--)
	{
		if(arr[i] < arr[i+1])
		{
			first_idx = i;
			break;
		}
	}
	
	if(first_idx == -1)
		return false;
	
	for(int i=N-1; i>first_idx; i--)
	{
		if(arr[first_idx] < arr[i])
		{
			int temp = arr[i];
			arr[i] = arr[first_idx];
			arr[first_idx] = temp;
			
			break;
		}
	}
	
	int* temp = new int[(N-1) - first_idx];

	for(int i=N-1; i>first_idx; i--)
	{
		temp[(N-1) - i] = arr[i];
	}
	
	for(int i=first_idx+1; i<N; i++)
		arr[i] = temp[i - (first_idx+1)];
	
	return true;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++)
		cin >> input_arr[i];
	
	
	int op_cnt(0);
	for(int i=1; i<=4; i++)
	{
		int k;
		cin >> k;
		
		for(int j=0; j<k; j++)
			op_arr[op_cnt++] = i; 
	}
	
	int max_output(-INT_MAX);
	int min_output(INT_MAX);
	
	while(true)
	{
		int sum = input_arr[0];
		
		for(int i=0; i<N-1; i++)
		{
			switch(op_arr[i])
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
		
		max_output = max(sum, max_output);
		min_output = min(sum, min_output);
		
		if(!next_permutaion(op_arr, N-1))
			break;
	}
	
	cout << max_output << endl;
	cout << min_output << endl;
}