#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> number;
vector<int> order;
int N, M;

void dfs(int num, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < cnt; i++)
			cout << number[order[i]] << ' ';
		cout << '\n';
		return;
	}

	for (int i = num; i < N; i++)
	{
		bool change = true;
		order.push_back(i);
		for (int j = 0; j < order.size()-1; j++)
		{
			if (number[i] == number[order[j]])
			{
				change = false;
				break;
			}
		}
		if(change)
			dfs(0, cnt + 1);
		order.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		number.push_back(num);
	}
	sort(number.begin(), number.end());

	dfs(0, 0);
}