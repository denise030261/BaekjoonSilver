#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void dfs(int num, int length)
{
	if (length == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = num; i <= N; i++)
	{
		v.push_back(i);
		dfs(i, length + 1);
		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	dfs(1, 0);
}
