#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int answer;

void circle(string A, string B, string C)
{
	int preanswer = 0;

	for (int i = 0; i < 4; i++)
	{
		if (A[i] != B[i])
			preanswer++;
		if (C[i] != B[i])
			preanswer++;
		if (A[i] != C[i])
			preanswer++;
	}

	if (preanswer < answer)
		answer = preanswer;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, N;
	map<string, int> order;
	vector<string> orderV;
	string mbti;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		order.clear();
		orderV.clear();

		answer = 999;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> mbti;
			if (order.find(mbti) != order.end())
			{
				order[mbti]++;
			}
			else
			{
				order.insert({ mbti, 1 });
			}
			
			orderV.push_back(mbti);
		}

		for (int p = 0; p < N - 2; p++)
		{
			for (int q = p + 1; q < N - 1; q++)
			{
				for (int r = q + 1; r < N; r++)
				{
					circle(orderV[p], orderV[q], orderV[r]);

					if (answer == 0)
						break;
				}
				if (answer == 0)
					break;
			}
			if (answer == 0)
				break;
		}
		cout << answer << '\n';
	}
}