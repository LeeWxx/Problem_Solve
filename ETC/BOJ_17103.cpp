#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MAX_NUMBER = 1000000;

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	bool check_arr[MAX_NUMBER+10] = {false, };
	
	for(int i = 2; i<=MAX_NUMBER; i++)
	{
		if(check_arr[i] == true)
			continue;
		
		for(int j = 2*i; j<MAX_NUMBER; j+=i)
			check_arr[j] = true;
	}
	
	int input_count;
	cin >> input_count; 
	
	while(input_count--)
	{
		int input_num;
		cin >> input_num;
		
		int count(0);
		for(int i = 2; i<input_num/2+1; i++)
		{
			if(check_arr[i] == false)
			{
				int x = input_num - i; 
				
				if(check_arr[x] != false)
					continue;
				
				count++;
			}
		}
		
		cout << count << '\n';
	}
	
	cout << endl;
	
}