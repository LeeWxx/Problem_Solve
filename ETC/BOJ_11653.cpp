#include <iostream>

using namespace std;

void setSieve(bool check_arr[], int n)
{
	for(int i = 2; i <= n; i++)
	{
		if(check_arr[i] == false)
		{
			for(int j = i*2; j <= n; j+=i)
				check_arr[j] = true;	
		}
	}
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_num;
	cin >> input_num;
	
	bool* check_arr = new bool[input_num+1] { false, };
	setSieve(check_arr, input_num);
	int loop_size = (input_num/2)+1;
		
	if (check_arr[input_num] == false && input_num != 1) 
	{
        cout << input_num << '\n';
    }
	else
	{
		for(int i = 2; i<loop_size; i++)
		{
			if(check_arr[i] != false)
			continue;
		
			while(input_num != 1)
			{
				if(input_num % i == 0)
				{
					cout << i << '\n';
					input_num /= i;
				}
				else 
					break;
		}
		
		}	
	}
	
	delete[] check_arr;
	
	cout << endl;
	
}