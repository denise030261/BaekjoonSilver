#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int n;
	cin >> n;
	long long int x_sum = 0;
	long long int y_sum = 0;

	vector<int> x;
	vector<int> y;

	for (long long int i = 0; i < n; i++)
	{
		long long int x_num;
		long long int y_num;
		cin >> x_num >> y_num;

		x.push_back(x_num);
		y.push_back(y_num);

	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	if (n % 2 != 0)
		n /= 2;
	else
	{
		n /= 2;
		n--;
	}

	long long int result = 0;

	for (long long int i = 0; i<x.size(); i++)
	{
		result += abs(x[i] - x[n]) + abs(y[i] - y[n]);
	}

	cout << result;
}