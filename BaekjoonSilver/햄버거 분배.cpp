#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int N;
	int K;
	int person = 0;
	string table;
	bool H_Exist[20000] = { 0, };
	cin >> N >> K;
	cin >> table;

	for (int i = 0; i < N; i++)
		if (table[i] == 'H')
			H_Exist[i] = true;

	for (int i = 0; i < N; i++)
	{
		if (table[i] == 'P')
		{
			for (int j = -K; j <= K; j++)
			{
				if(i+j>=0 && i+j<N)
					if (table[i + j] == 'H' && H_Exist[i+j])
					{
						H_Exist[i + j] = false;
						person++;
						break;
					}
			}
		}
	}

	cout << person;
}