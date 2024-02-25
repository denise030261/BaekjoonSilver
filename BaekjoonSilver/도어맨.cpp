#include <iostream>
#include <deque>
#include <cstdlib>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int X;
	int woman = 0;
	int man = 0;
	int result = 0;
	string people;

	cin >> X;
	cin >> people;

	while (people.length() != 0)
	{
		if (people[0] == 'W')
		{
			woman++;

			if (abs(woman - man) <= X)
			{
				result++;
				people.erase(0, 1);
			}
			else
			{
				if (people[1] == 'M')
				{
					woman--;
					man++;
					result++;
					people.erase(1, 1);
				}
				else
					break;
			}
		}

		else if (people[0] == 'M')
		{
			man++;

			if (abs(woman - man) <= X)
			{
				result++;
				people.erase(0, 1);
			}
			else
			{
				if (people[1] == 'W')
				{
					man--;
					woman++;
					result++;
					people.erase(1, 1);
				}
				else
					break;
			}
		}
	}
	cout << result;
}