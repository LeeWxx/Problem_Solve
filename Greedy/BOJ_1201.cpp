#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setBoundary(int N, int M, int K, vector<int>& vec)
{ 
	vec.push_back(K);
	N -= K;
	
	vector<int> set_vec;
	
	int set_cnt;
	int remainder;
	
	if(M != 1)
	{
		set_cnt = N / (M - 1);
		remainder = N % (M-1);	
	}
	else
		return;
	
	for(int i=0; i<M-1; i++)
	{
		int cnt = set_cnt;
		
		if(remainder > 0)
		{
			cnt++;
			remainder--;
		}
		
		set_vec.push_back(cnt);
	}
	
	
	for(int i=0; i<set_vec.size(); i++)
	{
		int elem = vec.back() + set_vec[i];
		vec.push_back(elem);
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M, K;
	cin >> N >> M >> K;
	
	if(N > M * K || N < M + K - 1)
	{
		cout << -1 << endl;
		return 0;
	}
	
	vector<int> boundary;
	setBoundary(N, M, K, boundary);
	
	vector<int> output;
	
	for(int i=1; i<= N; i++)
		output.push_back(i);
	
	int pre_boun = 0;
	for(int i=0; i<boundary.size(); i++)
	{
		int boun = boundary[i];
		reverse(output.begin() + pre_boun, output.begin() + boun);
		pre_boun = boun;
	}
	
	for(int i=0; i<N; i++)
		cout << output[i] << " ";
}




