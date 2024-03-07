#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int arr[500][500];
	int result = 0;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j - 1 >= 0 && j <= i - 1)
			{
				arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
			}
			else if (j - 1 < 0)
			{
				arr[i][j] += arr[i - 1][j];
			}
			else
			{
				arr[i][j] += arr[i - 1][j - 1];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (result < arr[n - 1][i])
		{
			result = arr[n - 1][i];
		}
	}

	cout << result;
}