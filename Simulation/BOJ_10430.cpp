#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int A;
	int B;
	int C;
	
	cin >> A >> B >> C;
	
	cout << (A+B)%C <<endl;
	cout << ((A%C) + (B%C))%C <<endl;
	cout << (A*B)%C <<endl;
	cout << ((A%C) * (B%C))%C <<endl;
	return 0;

}