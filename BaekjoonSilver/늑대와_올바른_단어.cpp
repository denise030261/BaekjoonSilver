#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool correct = true;
	string str;
	cin >> str;

	int num = 0;
	int check_num=0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'w' && i == 0)
			num++;

		else if (i >= 1)
		{
			if (str[i - 1] == 'w' && str[i] == 'w')
				num++;

			else if (str[i - 1] == 'w' && str[i] == 'o')
				check_num++;

			else if (str[i - 1] == 'o' && str[i] == 'o')
				check_num++;

			else if (str[i - 1] == 'o' && str[i] == 'l')
			{
				if (num == check_num)
					check_num = 1;
				else
				{
					correct = false;
					break;
				}
			}

			else if (str[i - 1] == 'l' && str[i] == 'l')
				check_num++;

			else if (str[i - 1] == 'l' && str[i] == 'f')
			{
				if (num == check_num)
					check_num = 1;
				else
				{
					correct = false;
					break;
				}
			}

			else if (str[i - 1] == 'f' && str[i] == 'f')
				check_num++;

			else if (str[i - 1] == 'f' && str[i] == 'w')
			{
				if (num == check_num)
				{
					num = 1;
					check_num = 0;
				}
				else
				{
					correct = false;
					break;
				}
			}

			else
			{
				correct = false;
				break;
			}
		}
		
		else
		{
			correct = false;
			break;
		}
	}

	if (str[str.length() - 1] != 'f' || num != check_num)
		correct = false;

	cout << correct;
}