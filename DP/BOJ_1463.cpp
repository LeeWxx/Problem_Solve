#include <iostream>
#include <limits.h>

using namespace std;

int min(int x, int y)
{
	if(x < y)
		return x;
	return y;
}

int solve(int num)
{
	
	if(num <= 1)
		return 0;
	
	int a = num % 2 + 1 + solve(num / 2);
	int b = num % 3 + 1 + solve(num / 3);
	
	return min(a,b);
}


int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_num;
	cin >> input_num;
	
	cout << solve(input_num) << endl; 
}