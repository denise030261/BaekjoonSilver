#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
int answer[10];
//bool check[10];

void dfs(int num, int length)
{
	if (length == M)
	{
		for (int i = 0; i < length; i++)
		{
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int last = 0;

	for (int i = num; i < N; i++)
	{
		if (arr[i] != last)
		{
			answer[length] = arr[i];
			last = arr[i];
			dfs(i, length + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	dfs(0,0);
}
