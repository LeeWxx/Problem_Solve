#include <iostream>
#include <string>

using namespace std;

const int divisor = 10007;
int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_num;
	cin >> input_num;
	
	int* data = new int[input_num+1] {0, };
	
	data[0] = 1;
	data[1] = 1;
	
	for(int i = 2; i<= input_num; i++)
	{
		data[i] = ((data[i-1] % divisor) + (2 * data[i-2] % divisor)) % divisor;
	}
	
	cout << data[input_num] << endl;
	
	delete[] data; 
}