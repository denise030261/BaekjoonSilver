#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num[11] = { 0, };
	int answer = 0;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] - '0' == 9)
		{
			num[6]++;
		}
		else
		{
			num[str[i]-'0']++;
		}
	}

	if (num[6] % 2 == 0)
	{
		num[6] /= 2;
	}
	else
	{
		num[6] /= 2;
		num[6]++;
	}

	for (int i = 0; i <= 8; i++)
	{
		answer = max(answer, num[i]);
	}

	cout << answer;
}