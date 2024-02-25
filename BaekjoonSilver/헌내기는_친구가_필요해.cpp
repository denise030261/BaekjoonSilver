#include <iostream>
#include <vector>

using namespace std;

bool visited[601][601] = { 0, };
char arr[601][601];
int moveX[4] = {-1,1,0,0};
int moveY[4] = { 0,0,-1,1 };
int answer = 0;
int N, M;

void dfs(int x,int y)
{
	if (!visited[x][y])
	{
		visited[x][y] = 1;
	}
	if (arr[x][y] == 'P')
		answer++;

	for (int i = 0; i < 4; i++)
	{
		if (x + moveX[i] > 0 && x + moveX[i] <= N && y + moveY[i] > 0 && y + moveY[i] <= M)
		{
			if (!visited[x + moveX[i]][y + moveY[i]] && 
				(arr[x + moveX[i]][y + moveY[i]]=='P'|| arr[x + moveX[i]][y + moveY[i]] == 'O'))
			{
				dfs(x + moveX[i], y + moveY[i]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 'I')
			{
				n = i;
				m = j;
				visited[i][j] = 1;
			}
		}
	}

	dfs(n, m);

	if (answer == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << answer;
	}
}