#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string number[101][101];
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == 1)
				number[i][j] = to_string(i);
			else if (j == i)
				number[i][j] = "1";
			else
			{
				int num,position;
				string long_str, short_str;

				if (number[i - 1][j - 1].length() > number[i - 1][j].length())
				{
					position = number[i - 1][j - 1].length();
					long_str = number[i - 1][j - 1];
					short_str = number[i - 1][j];
				}
				else
				{
					position = number[i - 1][j].length();
					long_str = number[i - 1][j];
					short_str = number[i - 1][j - 1];
				}

				reverse(long_str.begin(), long_str.end());
				reverse(short_str.begin(), short_str.end());
				
				bool plus = false;
				vector<char> str;
				for (int k = 0; k < position; k++)
				{
					if (short_str.length()>k)
					{
						if (plus)
							num = (long_str[k] - '0') + (short_str[k] - '0') + 1;
						else
							num = (long_str[k] - '0') + (short_str[k] - '0');
						
						str.push_back((num % 10) + '0');

						if (num >= 10)
							plus = true;
						else
							plus = false;
					}
					else
					{
						if (plus)
							num = (long_str[k] - '0') + 1;
						else
							num = (long_str[k] - '0');

						str.push_back((num % 10) + '0');

						if (num >= 10)
							plus = true;
						else
							plus = false;
					}

				}

				if (plus)
					str.push_back('1');

				number[i][j] = "";
				while (!str.empty())
				{
					number[i][j] += str.back();
					str.pop_back();
				}
			}
		}
	}
	cout << number[n][m];
} 