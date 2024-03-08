#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, n, answer, last;
	int arr[2][100000];

	cin >> T;

	while (T > 0)
	{
		answer = 0;
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}

		arr[0][1] += arr[1][0];
		arr[1][1] += arr[0][0];

		for (int i = 2; i < n; i++)
		{
			arr[0][i] += max(arr[1][i - 1], arr[1][i - 2]);
			arr[1][i] += max(arr[0][i - 1], arr[0][i - 2]);
		}

		answer = max(arr[0][n - 1], arr[1][n - 1]);

		cout << answer << '\n';

		T--;
	}
}