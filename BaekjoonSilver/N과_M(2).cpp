#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	vector<int> num;
	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		num.push_back(i);
		cout << i << ' ';
	}
	cout << '\n';

	while (num[0] < N - (M - 1))
	{
		int end = num.back() + 1;
		int position = 0;
		int over = 0;

		while (end > N - position)
		{
			over++;
			position++;
			num.pop_back();
			end = num.back() + 1;
		}
		num.pop_back();
		num.push_back(end);

		for (int i = 1; i <= over; i++)
		{
			num.push_back(end + i);
		}

		for (int i = 0; i < num.size(); i++)
			cout << num[i] << ' ';
		cout << '\n';
	}
}