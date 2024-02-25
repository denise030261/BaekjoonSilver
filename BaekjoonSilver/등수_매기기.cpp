#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int num;
	long long int result = 0;
	vector<int> order;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		order.push_back(num);
	}

	sort(order.begin(), order.end());

	for (int i = 0; i < N; i++)
		result += abs(order[i] - (i + 1));

	cout << result;
}