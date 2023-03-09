#include <iostream>

using namespace std;

int getZeroCount(int n)
{
	if (n % 5 == 0)
		return 1 + getZeroCount(n/5);
	return 0;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int input_num; 
	cin >> input_num;
	
	int count(0);
	for(int i=5; i<=input_num; i+=5)
	{
		count+=getZeroCount(i);
	}

	cout << count << endl;
	
	return 0;
}