#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	string str;
	cin >> N;

	map<string, int> m;

	for (int i = 0; i < N; i++)
	{
		cin >> str;

		if (m.find(str) != m.end())
		{
			m[str]++;
		}
		else
		{
			m.insert({ str,1 });
		}
	}

	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b)
		{
			if (a.second == b.second)
				return a.first < b.first;
			else
				return a.second > b.second;
		});

	cout << v[0].first;
}