#include <iostream>
#include <vector>
#define INT_MAX 987654321

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int result = 0;
	int start = 0;
	int dp[1001] = { 0, };
	vector<int> order;
	int N;
	cin >> N;

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		order.push_back(num);
	}

	for (int i = 0; i < N; i++)
	{
		bool zero = true;
		for (int j = order[i]-1; j >= start; j--)
		{	
			if (dp[j] != 0)
			{
				dp[order[i]] = max(dp[order[i]], dp[j] + 1);
				zero = false;
			}
		}

		if (zero)
			dp[order[i]] = 1;

		if (i == 0)
			start = INT_MAX;
		start = min(start, order[i]);
	}

	for (int i = 0; i < N; i++)
	{
		result = max(result, dp[order[i]]);
	}

	cout << result;
}