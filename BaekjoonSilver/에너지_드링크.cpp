#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<long double> v;
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		long double num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	long double DrinkMix = v[v.size()-1];
	for (int i = 0; i < N-1; i++)
	{
		DrinkMix += v[i] / 2;
	}

	cout << DrinkMix;
}