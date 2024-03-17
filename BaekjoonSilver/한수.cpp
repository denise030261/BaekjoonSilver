#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string N,str;
	int N_num;
	int answer = 99;

	cin >> N;
	N_num = stoi(N);

	if (N_num<=99)
	{
		cout << N;
		return 0;
	}
	else
	{
		for (int i = 100; i <= 1000; i++)
		{
			if (i <= N_num)
			{
				str = to_string(i);
				int compare;
				compare = str[0] - str[1];
				if (compare == str[1] - str[2])
				{
					answer++;
				}
			}
		}
	}
	
	cout << answer;
}