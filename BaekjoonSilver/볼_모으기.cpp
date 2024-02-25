#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int RedBall = 0; int BlueBall = 0;
	int LeftBall = 0; int RightBall = 0;
	char LeftColor = ' '; char RightColor = ' ';
	bool Change = false; char Ball; int result = 987654321;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Ball;
		if (i == 0)
		{
			LeftColor = Ball;
			LeftBall++;
		}
		else if (!Change && LeftColor == Ball)
			LeftBall++;
		else if (!Change && LeftColor != Ball)
		{
			Change = true;
			RightBall++;
			RightColor = Ball;
		}
		else if (Change && RightColor == Ball)
			RightBall++;
		else if (Change && RightColor != Ball)
		{
			RightBall = 1;
			RightColor = Ball;
		}

		if (Ball == 'R')
			RedBall++;
		else
			BlueBall++;
	}

	if (LeftColor == 'R')
	{
		result = min(result, BlueBall);
		result = min(result, RedBall - LeftBall);
	}
	else
	{
		result = min(BlueBall - LeftBall, result);
		result = min(RedBall, result);
	}
	if (RightColor == 'R')
	{
		result = min(RedBall - RightBall, result);
		result = min(BlueBall, result);
	}
	else
	{
		result = min(BlueBall - RightBall, result);
		result = min(RedBall, result);
	}
	cout << result;
}