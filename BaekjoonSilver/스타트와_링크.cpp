#include <iostream>

using namespace std;

int member[21][21] = { 0, };
bool visited[21] = { 0, };
int answer = 987654321;
int self = 0;
int other = 0;
int N = 0; 

void dfs(int length, int current)
{
	if (length == N / 2)
	{
		self = 0;
		other = 0;
		for (int i = 1; i <= N-1; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				if (visited[i] && visited[j])
				{
					self += member[i][j];
					self += member[j][i];
				}
				else if(!visited[i] && !visited[j])
				{
					other += member[i][j];
					other += member[j][i];
				}
			}
		}

		answer = min(answer, abs(self - other));
	}
	else
	{
		for (int i = current+1; i <= N; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				dfs(length + 1, i);
				visited[i] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> member[i][j];
		}
	}

	dfs(0,0);

	cout << answer;
}