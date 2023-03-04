#include <iostream>

using namespace std;


bool isPrime(int n)
{	
	if (n < 2)
		return false;
		
	for(int i = 2; i*i <= n; i++)
	{
		if(n%i == 0)
			return false;
	}
	
	return true;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int input_count;
	cin >> input_count;
		
	int prime_count(0);
	
	while(input_count--)
	{
		int n; 	
		cin >> n;

		if(isPrime(n))
			prime_count++;	
	}
	
	cout << prime_count << endl;
}