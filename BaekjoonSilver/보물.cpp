#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	vector<int> A;
	vector<int> B;
	cin >> N;

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		A.push_back(num);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		B.push_back(num);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), compare);

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer += A[i] * B[i];
	}

	cout << answer;
}