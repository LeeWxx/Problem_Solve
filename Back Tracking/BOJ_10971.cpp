#include <iostream>
#include <climits>

using namespace std;

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

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int input_count;
	cin >> input_count; 
	
	int* permutaion_arr = new int[input_count];
	
	for(int i=0; i<input_count; i++)
		permutaion_arr[i] = i;
	
	int** input_arr = new int*[input_count];
	
	for(int i=0; i<input_count; i++)
		input_arr[i] = new int[input_count];
	
	for(int i=0; i<input_count; i++)
	{
		for(int j=0; j<input_count; j++)
		{
			cin >> input_arr[i][j];
		}
	}
	
	int output = INT_MAX;
	bool result = true;
	
	while(result)
	{
		int sum(0);
		bool check = false;
		
		for(int i=0; i<input_count; i++)
		{
			int departure_idx;
			int arrival_idx;
			
			if(i == input_count-1)
			{
				departure_idx = permutaion_arr[input_count-1];
				arrival_idx = permutaion_arr[0];
			}
			else
			{
				departure_idx = permutaion_arr[i];
				arrival_idx = permutaion_arr[i+1];	
			}
			
			int cost = input_arr[departure_idx][arrival_idx];
			
			if(cost == 0)
			{
				check = true;
				break;
			}
			
			sum += cost;
		}
		
		if(!check)
			output = min(sum, output);
		
		result = next_permutaion(permutaion_arr, input_count);
	}
	
	cout << output << endl;
}