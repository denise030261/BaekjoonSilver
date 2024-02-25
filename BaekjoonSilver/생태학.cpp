#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str;
	map<string, int> m;
	int num = 0;

	while (getline(cin, str))
	{
		if (m.find(str) != m.end())
		{
			m[str] ++;
		}
		else
		{
			m.insert({ str,1 });
		}
		num++;
	}

	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b)
		{
			return a.first < b.first;
		});

	cout << fixed;
	cout.precision(4);
	for (pair<string, int> it : v)
	{
		float result = round(it.second / float(num) * 100 * 10000) / 10000;
		cout << it.first << ' ' << result << endl;
	}
}