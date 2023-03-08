#include <iostream>

using namespace std;

int factorial(int n)
{
	if(n == 1 || n == 0 )
		return 1;
	
	return n * factorial(n-1);
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int input_num; 
	
	cin >> input_num;
	
	int result = factorial(input_num);
	
	cout << result << endl;
	
	return 0;
}