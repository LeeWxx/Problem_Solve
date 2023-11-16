#include <iostream>
#include <string>

using namespace std;

const int IVXL[4] = {1, 5, 10, 50};
bool checked[1001];

void recursion(int N, int idx, int last, int sum)
{
	if(idx == N)
	{
		checked[sum] = true;
		return;
	}
		
	
	for(int i=last; i<4; i++)
		recursion(N, idx+1, i, sum + IVXL[i]);
	
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	recursion(N, 0, 0, 0);
	
	int answer(0);
	for(int i=1; i<1001; i++)
	{
		if(checked[i])
			answer++;
	}	
	
	
	cout << answer;
}



