#include <iostream>
#include <climits>

using namespace std;

const int MAX_INPUT_SIZE = 20;
int ability_arr[MAX_INPUT_SIZE][MAX_INPUT_SIZE];

int result = INT_MAX;

void getAnotherTeam(int N, int team_size, int* arr, int* another_arr)
{
	int idx(0);
	
	for(int i=0; i<N; i++)
	{
		bool check(false);
		
		for(int j =0; j<team_size; j++)
		{
			if(i==arr[j])
				check=true;
		}
		
		if(!check)
		{
			another_arr[idx] = i;
			idx++;
		}
	}
}

int getAbility(int* idx_arr, int team_size)
{
	int sum(0);
	
	for(int i=0; i<team_size-1; i++)
	{
		for(int j=i+1; j<team_size; j++)
		{
			int i_idx = idx_arr[i];
			int j_idx = idx_arr[j];
			
			sum += ability_arr[i_idx][j_idx] + ability_arr[j_idx][i_idx];
		}
	}
	
	return sum;
}

int getGap(int team_size, int N, int* arr)
{
	int another_team_size = N - team_size;
	int* another_arr = new int[another_team_size];
	
	getAnotherTeam(N, another_team_size, arr, another_arr);
	
	int start_ability = getAbility(arr, team_size);
	int link_ability = getAbility(another_arr, another_team_size);
	
	int gap = start_ability - link_ability;
	
	if(gap < 0)
		gap *= -1;
	
	return gap;
	
	delete[] another_arr;
}

void solve(int idx, int team_size, int N, int last, int* arr)
{
	if(idx == team_size)
	{
		result = min(getGap(team_size, N, arr), result);
		return;
	}
	
	for(int i=last+1; i<N; i++)
	{
		if(idx == 0 && i != 0)
			return;
		
		arr[idx] = i;
		solve(idx + 1, team_size, N, i, arr);
	}
}


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	
	int* arr = new int[N];
	int* idx_arr = new int[N];
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> ability_arr[i][j];
		}
	}
	
	
	solve(0, N/2, N, -1, arr);
	
	cout << result << endl;
	
	delete[] arr;
	delete[] idx_arr;
}