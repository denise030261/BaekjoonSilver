#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int arr[10001];
	int result = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	if (n >= 3)
	{
		int mid;
		if (arr[0] <= arr[1] && arr[0] <= arr[2])
		{
			result += arr[1] + arr[2];
			mid = 0;
		}
		else if (arr[1] <= arr[0] && arr[1] <= arr[2])
		{
			result += arr[0] + arr[2];
			mid = 1;
		}
		else if (arr[2] <= arr[0] && arr[2] <= arr[1])
		{
			result += arr[0] + arr[1];
			mid = 2;
		}

		for (int i = 3 + mid; i < n; i++)
		{
			if()
		}
	}
}
//±èÁö¿ì ÇÐ»ý