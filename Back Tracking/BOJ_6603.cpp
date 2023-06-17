#include <iostream>

const int LOTTO_LENGTH = 6;
const int MAX_OUTPUT_SIZE = 12;
int output_arr[MAX_OUTPUT_SIZE];

using namespace std;

void print()
{
	for(int i=0; i<LOTTO_LENGTH-1; i++)
		cout << output_arr[i] << " ";
	
	cout << output_arr[LOTTO_LENGTH-1] << "\n";
}

void recursion(int output_idx, int input_idx, int k, int* input_arr)
{
	if(output_idx == LOTTO_LENGTH)
	{
		print();
		return;
	}
	
	for(int i = input_idx; i<k; i++)
	{
		output_arr[output_idx] = input_arr[i];
		recursion(output_idx+1, i+1, k, input_arr);
	}
	
	return;
}




int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while(true)
	{
		int k;
		cin >> k;
		
		if(k == 0)
			break;
		
		int* input_arr = new int[k];
		
		for(int i=0; i<k; i++)
			cin >> input_arr[i];
		
		recursion(0, 0, k, input_arr);
		
		delete[] input_arr;
		
		cout << "\n";
	}
}