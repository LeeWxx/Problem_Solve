#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	vector<int> vec;
	
	for(int i=0; i<N; i++)
	{
	 	int num;
	 	cin >> num;
		
	 	auto iter = lower_bound(vec.begin(), vec.end(), num);
		
	 	if(iter == vec.end())
	 		vec.push_back(num);
	 	else
			*iter = num;
	 }
	
	cout << vec.size() << endl;
	
	 return 0;
}