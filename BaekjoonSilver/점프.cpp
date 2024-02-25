#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int route[10000] = { 0, };
	long long int map[10000] = { 0, };
	int N;
	
	cin >> N;
	for (int i = 0; i < N * N; i++)
	{
		cin >> route[i];
	}
	map[0]++;

	for (int i = 0; i < N * N; i++)
	{
		if (route[i] > 0)
		{
			if (i + route[i]<N * N && (i + route[i]) % N>i % N)
				map[i + route[i]]+=map[i];
			if (i + route[i] < N * N && i + N * route[i])
				map[i + N * route[i]]+=map[i];
		}
	}

	cout << map[N * N - 1];
}