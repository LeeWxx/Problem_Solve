#include <iostream>
#include <string>

using namespace std;

const int MAX_INPUT = 100000;

struct Student
{
	string name;
	int korean;
	int english;
	int math;
};

Student students[MAX_INPUT+1];
Student copy_arr[MAX_INPUT+1];

bool comp(Student a, Student b)
{
	if(a.korean == b.korean && a.english == b.english && a.math == b.math)
		return a.name < b.name;
		
	if(a.korean == b.korean && a.english == b.english)
		return  a.math > b.math;
	
	if(a.korean == b.korean)
		return  a.english < b.english;
	
	return a.korean > b.korean;
}

void merge(int left, int right)
{
	int mid = (left + right) / 2;
	int l_idx = left;
	int r_idx = mid + 1;
	
	int copy_idx = left;
	
	while(l_idx <= mid && r_idx <= right)
	{
		if(comp(students[l_idx], students[r_idx]))
			copy_arr[copy_idx++] = students[l_idx++];
		else
			copy_arr[copy_idx++] = students[r_idx++];
	}
	
	while(l_idx <= mid)
		copy_arr[copy_idx++] = students[l_idx++];
	
	while(r_idx <= right)
		copy_arr[copy_idx++] = students[r_idx++];
	
	for(int i=left; i<=right; i++)
		students[i] = copy_arr[i];
}

void mergeSort(int left, int right)
{
	if(left >= right)
		return;
	
	int mid = (left + right) / 2;
	
	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	merge(left, right);
}

void print(int N)
{
	for(int i=1; i<=N; i++)
		cout << students[i].name << "\n";
}

void input(int N)
{
	for(int i=1; i<=N; i++)
	{
		string name;
		int korean, english, math;
		
		cin >> name >> korean >> english >> math;
		
		Student student;
		student.name = name;
		student.korean = korean;
		student.english = english;
		student.math = math;
		
		students[i] = student;
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	
	int N;
	cin >> N;
	
	input(N);
	mergeSort(1, N);
	print(N);
}






