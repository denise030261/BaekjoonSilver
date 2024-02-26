#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int treeFloor[100001] = { 0, };

void dfs(vector<vector<int>> &arr,int target)
{
	for (int p = 0; p < arr[target].size(); p++)
	{
		if (treeFloor[arr[target][p]] == 0)
		{
			treeFloor[arr[target][p]] = target;
			dfs(arr, arr[target][p]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N,a,b;
	cin >> N;

	vector<vector<int>> v1(N+1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		v1[a].push_back(b);
		v1[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		if (i == 1)
		{
			treeFloor[1] = 1;
		}
		for (int j = 0; j < v1[i].size(); j++)
		{
			if (treeFloor[v1[i][j]] == 0 || i == 1)
			{
				treeFloor[v1[i][j]] = i;
				dfs(v1, v1[i][j]);
			}
		}

	}

	for (int i = 2; i <= N; i++)
	{
		cout << treeFloor[i] << '\n';
	}
}

