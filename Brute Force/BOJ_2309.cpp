#include <iostream>

using namespace std;

const int INPUT_COUNT = 9;
const int ANSWER_SUM = 100;


void bubble_sort(int list[], int n)
{
  int i, j, temp;

  for(i=n-1; i>0; i--)
  {
    for(j=0; j<i; j++)
	{
      if(list[j]>list[j+1])
	  {
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
}

void solve(int arr[], int target_sum)
{
	for(int i=0; i<INPUT_COUNT; i++)
	{
		for(int j=i; j<INPUT_COUNT; j++)
		{
			if(arr[i] + arr[j] == target_sum)
			{
				for(int k=0; k<INPUT_COUNT; k++)
				{
					if(k != i && k != j)
					{
						cout << arr[k] << "\n";
					}	
				}
				
				return;
			}
		}
	}
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_arr[INPUT_COUNT];
	
	int input_sum(0);
	
	for(int i=0; i<INPUT_COUNT; i++)
	{
		cin >> input_arr[i];
		input_sum += input_arr[i];
	}
	
	bubble_sort(input_arr,INPUT_COUNT);
	
	int target_sum = input_sum - ANSWER_SUM;
	solve(input_arr, target_sum);
}