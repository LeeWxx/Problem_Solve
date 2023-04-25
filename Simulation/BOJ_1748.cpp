#include <iostream>
#include <cmath>

using namespace std;


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int input_num; 
	cin >> input_num;
	
	int number_of_digits(0);
	
	int quotient = input_num; 
	
	while(quotient != 0)
	{
		quotient /= 10;
		number_of_digits++;
	}
	
	int sum(0);
	int count_sum(0); 
	
	for(int i=1; i<=number_of_digits; i++)
	{
		int count;
		
		if(i == number_of_digits)
			count = input_num - count_sum;
		else
			count = pow(10, i) - 1 - count_sum;

		sum += count * i;
		count_sum += count;
	}
	
	cout << sum << endl;
}