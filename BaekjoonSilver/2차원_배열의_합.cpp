#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int arr[301][301] = { 0, };
	long long int result = 0;
	int N, M, K;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];

	cin >> K;
	int i, j, x, y;
	for (int k = 0; k < K; k++)
	{
		cin >> i >> j >> x >> y;

		for (int p = i; p <= x; p++)
			for (int q = j; q <= y; q++)
				result += arr[p][q];

		cout << result << '\n';
		result = 0;
	}
}