#include <cstring>
#include <iostream>

using namespace std;

int N;
string str[50];
int Friend[50][50];
int result[50];
int relation = 0;

void dfs(int point,int num)
{
	for (int i = 0; i < N; i++)
	{
		if (str[num][i] == 'Y' && relation<2)
		{
			if (Friend[point][i] == 0)
			{
				result[point]++;
				Friend[point][i] = 1;
			}

			relation++;
			dfs(point,i);
			relation--;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> str[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			Friend[i][i] = 1;

		dfs(i, i);
		relation = 0;
	}

	int output = 0;
	for (int i = 0; i < N; i++)
		output = max(output, result[i]);
	cout << output;
}