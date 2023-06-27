#include <iostream>

using namespace std;


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	
	int S;
	cin >> S;
	
	int* input_arr = new int[N];
	int cnt(0);

	for(int i=0; i<N; i++)
		cin >> input_arr[i];
	
	for(int i=1; i<(1<<N); i++)
	{
		int sum(0);
		for(int j=0; j<N; j++)
		{
			if((1 << j) & i)
				sum += input_arr[j];
				
		}
		
		if(sum == S)
			cnt++;
			
	}
	
	cout << cnt << endl;
	
	delete[] input_arr; 
}