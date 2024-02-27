#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10];
int answer[10];
bool check[10];
int N, M;

void dfs(int length)
{
	if (length == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int last = 0;

	for (int i = 0; i < N; i++)
	{
		if (!check[i] && arr[i] != last)
		{
			answer[length] = arr[i];
			last = answer[length];
			check[i] = true;
			dfs(length + 1);
			check[i] = false;
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

	sort(arr, arr+N);

	dfs(0);
}