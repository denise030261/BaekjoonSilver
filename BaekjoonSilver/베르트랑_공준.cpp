#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, answer;
	bool notdecimal[246913] = { 0, };
	notdecimal[1] = 1;

	for (int i = 2; i <= 246912; i++)
	{
		for (int j = 2; i * j <= 246912; j++)
		{
			notdecimal[i * j] = true;
		}
	}
	while (1)
	{
		answer = 0;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		else
		{
			for (int i = n + 1; i <= 2 * n; i++)
			{
				if (!notdecimal[i])
				{
					answer++;
				}
			}
			cout << answer << '\n';
		}
	}
}
