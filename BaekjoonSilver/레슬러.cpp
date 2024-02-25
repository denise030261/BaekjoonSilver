#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> player_STR;
	vector<int> player_RING;
	map <int, int> player;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int STR;
		int RING;
		cin >> STR >> RING;
		player_STR.push_back(STR);
		player_RING.push_back(RING);
		player.insert({ i + 1,0 });
	}

	for (int i = 0; i < N; i++)
	{
		int player_me;
		int player_you;
		for (int j = i + 1; j < N; j++)
		{
			player_me = player_STR[i] + player_RING[i] * player_STR[j];
			player_you = player_STR[j] + player_RING[j] * player_STR[i];
			if (player_me > player_you)
				player[i + 1]++;
			else
				player[j + 1]++;
		}
	}
	
	vector<pair<int, int>> order(player.begin(), player.end());
	sort(order.begin(), order.end(), compare);
	for (auto num : order)
		cout << num.first << '\n';
	
}