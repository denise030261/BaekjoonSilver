#include <iostream>
#include <cmath>

using namespace std;

char map[101][101];
int visited[101][101] = { 0, };
int ResultWhite = 0; //아군의 위력
int AddWhite = 0; //한 부위의 아군의 위력
int ResultBlue = 0; //적군의 위력
int AddBlue = 0; //한 부위의 적군의 위력

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int col, int row,char color)
{
	for (int i = 0; i < 4; i++)
	{
		if (row + dx[i] > 0 && col + dy[i] > 0 && visited[col + dy[i]][row + dx[i]] == 0 
			&& map[col + dy[i]][row + dx[i]]==color)
		{
			visited[col + dy[i]][row + dx[i]] = 1;
			if (color == 'W')
			{
				AddWhite++;
				dfs(col + dy[i], row + dx[i], 'W');
			}
			else if (color == 'B')
			{
				AddBlue++;
				dfs(col + dy[i], row + dx[i], 'B');
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M; // N은 가로, M은 세로
	cin >> N >> M;

	for(int i=1;i<=M;i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
		{
			if (visited[i][j] == 0)
			{
				visited[i][j] = 1;

				if (map[i][j] == 'W')
				{
					AddWhite++;
					dfs(i, j, 'W');
					ResultWhite += pow(AddWhite, 2);
					AddWhite = 0;
				}
				else if (map[i][j] == 'B')
				{
					AddBlue++;
					dfs(i, j, 'B');
					ResultBlue += pow(AddBlue, 2);
					AddBlue = 0;
				}
			}
		}

	cout << ResultWhite << ' ' << ResultBlue;
}