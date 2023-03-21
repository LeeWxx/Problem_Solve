#include <iostream>
#include <string>

using namespace std;

string intToAscii(int number) {
	string s(1, char(number));
   	return s;
}

string strMerge(string result, int num)
{
	if(num >= 10)
	{
		num += 55;
		result = intToAscii(num) + result;
	}
	
	else
		result = to_string(num) + result;
	
	return result;
}

void solve(int N, int B, string result)
{

	int quotient = N / B;
	int remainder = N % B;	
		
	result = strMerge(result,remainder);
	
	if(quotient < B)
	{
		if (quotient != 0)
			result = strMerge(result, quotient);
		cout << result << endl;
		return;
	}
	
	N = quotient;
	solve(N, B, result);
	return;
}


int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	int B;
	string result("");
	cin >> N >> B;
	
	solve(N, B, result);
}