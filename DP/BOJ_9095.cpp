#include <iostream>

using namespace std;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_count;
	cin >> input_count;
	
	while(input_count--)
	{
		int input_num;
		cin >> input_num;
		
		int given_case[3] = {1, 2, 4};
		if(input_num <= 3)
		{
			cout << given_case[input_num-1] << "\n";
			continue;
		}
		
		int* data = new int[input_num+1];
		
		for(int i = 0; i<3; i++)
			data[i] = given_case[i];
		
		for(int i = 3; i <= input_num; i++)
		{
			data[i] = data[i-3] + data[i-2] + data[i-1];
		}
		
		cout << data[input_num-1] << "\n";
	
		delete[] data;
		data = NULL;
	}
}