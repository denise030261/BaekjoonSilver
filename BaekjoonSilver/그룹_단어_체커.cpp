#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	bool correct = true;
	int alp[26] = { 0, };
	int result = 0;
	string str;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			if(j==0)
				alp[str[j] - 'a']++;
			else
			{
				if (alp[str[j] - 'a'] == 0)
					alp[str[j] - 'a']++;
				else if (str[j] == str[j - 1])
					continue;
				else
				{
					correct = false;
					break;
				}
			}
		}
		if (correct)
			result++;
		else
			correct = true;
		memset(alp, 0, sizeof(alp));
	}

	cout << result;
}
