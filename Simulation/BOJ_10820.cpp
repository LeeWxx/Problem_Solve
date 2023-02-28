#include <iostream>
#include <string>

using namespace std;


void print(int arr[], int n)
{
	int i = 0; 
	while(i < n - 1)
	{
		cout << arr[i] << " ";
		i++;
	}
	
	cout << arr[i] << endl;
}

void reset(int arr[], int n)
{
	for(int i =0; i<n; i++)
		arr[i] = 0;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int output_arr[4] = {0,};
	string input_str;
	while(getline(cin,input_str))
	{
		if(input_str.size() == 0)
			break;
		for(char ch : input_str)
		{
			// if(ch == '\n')
			// {
			// 	print(output_arr, sizeof(output_arr)/sizeof(int));
			// 	reset(output_arr, sizeof(output_arr)/sizeof(int));
			// }
			if(ch >= 'a' && ch <= 'z')
			{
				output_arr[0]++;
			}
			else if(ch >= 'A' && ch <= 'Z')
			{
				output_arr[1]++;
			}
			else if(isdigit(ch))
			{
				output_arr[2]++;
			}
			else if(ch == ' ')
			{
				output_arr[3]++;
			}
			
		}
		
		print(output_arr, sizeof(output_arr)/sizeof(int));
		reset(output_arr, sizeof(output_arr)/sizeof(int));
	}
	
	return 0;

}