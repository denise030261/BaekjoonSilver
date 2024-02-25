#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, N, result;
	cin >> T;
	while (T != 0)
	{
		vector<pair<int, int>> v;
		vector<int> store;
		cin >> N;

		result = 0;
		for (int i = 0; i < N; i++)
		{
			int element1, element2;
			cin >> element1 >> element2;
			v.push_back(pair<int, int>(element1, element2));
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < N; i++)
		{
			if (i == 0)
				store.push_back(v[i].second);
			else
				store.push_back(min(store[i - 1], v[i].second));
		}

		for (int i = 0; i < N; i++)
		{
			if (v[i].second <= store[i])
				result++;
		}

		cout << result << '\n';
		T--;
	}
}

