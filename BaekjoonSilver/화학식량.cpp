#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int bracket = 0;
	int order[101] = {0,};
	string str;

	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
			bracket++;
		else if (str[i] == 'H')
		{
			if (i + 1 < str.length())
			{
				if (str[i + 1] >= '2' && str[i + 1] <= '9')
				{
					order[bracket] += 1 * (str[i + 1] - '0');
					i++;
				}
				else
					order[bracket] += 1;
			}
			else
				order[bracket] += 1;
		}
		else if (str[i] == 'O')
		{
			if (i + 1 < str.length())
			{
				if (str[i + 1] >= '2' && str[i + 1] <= '9')
				{
					order[bracket] += 16 * (str[i + 1] - '0');
					i++;
				}
				else
					order[bracket] += 16;
			}
			else
				order[bracket] += 16;
		}
		else if (str[i] == 'C')
		{
			if (i + 1 < str.length())
			{
				if (str[i + 1] >= '2' && str[i + 1] <= '9')
				{
					order[bracket] += 12 * (str[i + 1] - '0');
					i++;
				}
				else
					order[bracket] += 12;
			}
			else
				order[bracket] += 12;
		}
		else if (str[i] == ')') 
		{
			if (i + 1 < str.length())
			{
				if (str[i + 1] >= '2' && str[i + 1] <= '9')
				{
					order[bracket] *= (str[i + 1] - '0');
					order[bracket - 1] += order[bracket];
					order[bracket] = 0;
					bracket--;
					i++;
				}
				else
				{
					order[bracket - 1] += order[bracket];
					order[bracket] = 0;
					bracket--;
				}
			}
			else
			{
				order[bracket - 1] += order[bracket];
				order[bracket] = 0;
				bracket--;
			}
		}
	}

	cout << order[0];
}