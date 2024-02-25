#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int N, M, K; // N은 농장 층수, M은 비가 오는 횟수, K는 버틸 수 있는 빗물의 양
	long long int total_rain = 0;
	int result_order = 0;
	bool check = false;
	vector<int> floor_store;

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++)
	{
		long long int floor, rain;
		cin >> floor >> rain;
		total_rain += rain;

		if (total_rain > K && !check)
		{
			result_order = i + 1;
			check = true;
		}
		else if (!check)
			floor_store.push_back(floor);
	}

	if (check)
	{
		sort(floor_store.begin(), floor_store.end());
		cout << result_order << ' ' << floor_store[0];
	}
	else
		cout << -1;
}