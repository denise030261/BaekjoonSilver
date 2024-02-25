#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long  N;
	cin >> N;
	vector<long long> solution;

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		solution.push_back(num);
	}

	sort(solution.begin(), solution.end());

	long long bound = round(N * 0.15);

	long long answer = 0;
	for (int i = bound; i < N - bound; i++)
	{
		answer += solution[i];
	}

	float divide = N - bound * 2;

	if (N == 0)
	{
		cout << 0;
		return 0;
	}

	cout << round(answer/ divide);
}