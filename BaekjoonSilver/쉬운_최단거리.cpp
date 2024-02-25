#include <iostream>
#include <queue>

using namespace std;

int n, m;
int moveX[4] = { 0,0,-1,1 };
int moveY[4] = { -1,1,0,0 };
int arr[1001][1001];
int answer[1001][1001] = { 0, };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	answer[x][y] = 1;

	while (!q.empty())
	{
		int frontx = q.front().first;
		int fronty = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dx = frontx + moveX[i];
			int dy = fronty + moveY[i];

			if (dx > 0 && dx <= n && dy > 0 && dy <= m)
			{
				if (!answer[dx][dy] && arr[dx][dy] != 0)
				{
					answer[dx][dy] = answer[frontx][fronty] + 1;
					q.push({ dx, dy });
				}
			}
		}
	}
}

int main()
{
	int x, y;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i + 1][j + 1];

			if (arr[i + 1][j + 1] == 2)
			{
				x = i + 1;
				y = j + 1;
			}
			
		}
	}

	bfs(x, y);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << 0 << ' ';
			}
			else
			cout << answer[i][j]-1 << ' ';
		}
		cout << '\n';
	}
}