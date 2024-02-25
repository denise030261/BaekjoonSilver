#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	int order = 0;
	int num[1001] = { 0, };
	cin >> N >> K;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j * i <= N; j++)
		{
			if (num[i * j] == 0)
			{
				num[i * j] = 1;
				order++;
			}
			
			if (order == K)
			{
				cout << i * j;
				return 0;
			}
		}
	}
}