#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; //���� �� ��
	int S; //���� ������ ó��
	int M; //�ִ��� ���� ����
	cin >> N >> S >> M;

	int V[51];
	int dp[51][1001] = { 0, };

	for (int i = 1; i <= N; i++)
		cin >> V[i];

	dp[0][S] = 1;

	int num;
	for(int i=1;i<=N;i++)
		for (int j = 0; j <= M; j++)
		{
			if (dp[i - 1][j]) 
			{
				num = j + V[i];
				if (num <= M)
					dp[i][num] = 1;

				num = j - V[i];
				if (num >= 0)
					dp[i][num] = 1;
			}
		}

	for (int i = M; i >= 0; i--)
	{
		if (dp[N][i])
		{
			cout << i;
			return 0;
		}
	}

	cout << -1;
	return 0;
}