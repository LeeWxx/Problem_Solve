#include <iostream>

using namespace std;

void print(int input, int a, int b)
{
	cout << input << " = " << a << " + " << b << '\n';
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int input(-1);

	bool *check_arr = new bool[1000001] {false, };
	
	for(int i = 3; i <= 1000000; i+=2)
	{
		for(int j = i*2; j <= 1000000; j+=i)
			check_arr[j] = true;
	}
	
	while(true)
	{
		cin >> input;
		
		if(!input)
			break;
		
		for(int i = 3; i < input/2+1; i+=2)
		{
			if(check_arr[i] == true)
				continue;
				
			int find_num = input - i;
			if(check_arr[find_num] == false)
			{
				print(input, i , find_num);
				break;	
			}
			
			if(i == input-1)
				cout << "Goldbach's conjecture is wrong." << "\n";
		}
	}
	
	delete[] check_arr;
	check_arr = NULL;
	
	cout << endl;
	
	return 0;
}