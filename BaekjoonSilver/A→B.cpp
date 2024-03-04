#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int A, B;
	int answer = 1;

	cin >> A >> B;

	while (1)
	{
		if (A > B)
		{
			cout << -1;
			return 0;
		}
		else if (A == B)
		{
			cout << answer;
			return 0;
		}

		if (B % 10 == 1)
		{
			B /= 10;
			answer++;
		}
		else if (B % 2 != 0)
		{
			cout << -1;
			return 0;
		}
		else
		{
			B /= 2;
			answer++;
		}
	}
}