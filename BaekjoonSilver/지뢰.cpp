#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> order;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		order.push_back(num);
	}

	int center = 0;
	bool low = false;
	for (int i = 0; i < N; i++)
	{
		if (i + 1 >= N && low)
		{
			cout << center + 1;
			break;
		}
		else if (i + 1 >= N && !low)
		{
			cout << i + 1;
			break;
		}

		if (order[i] < order[i + 1] && !low)
			center = i + 1;
		else if (order[i] > order[i + 1] && !low)
		{
			low = true;
		}
		else if (order[i] == order[i + 1] || (order[i] < order[i + 1] && low))
		{
			cout << center + 1 << '\n';
			center = i + 1;
			low = false;
		}
	}
}