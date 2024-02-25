#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int T;
	string n;
	int zero;

	cin >> T;
	while (T != 0)
	{
		vector<int> card;
		zero = 0;
		cin >> n;
		for (int i = 0; i < n.length(); i++)
		{
			if (n[i] == '6')
				card.push_back(9);
			else if (n[i] == '0')
			{
				zero++;
				card.push_back(0);
			}
			else
				card.push_back(n[i] - '0');
		}

		sort(card.begin(), card.end());

		string str_a;
		string str_b;
		string str_result;
		if (zero > n.length() / 2)
		{
			str_a = card[card.size() - 1]+'0';
			for (int i = card.size() - 2; i >= 0; i--)
				str_b += card[i]+'0';
			str_result = to_string(stoi(str_a) * stoi(str_b));
		}
		else if (n.size() == 2)
		{
			str_result = to_string(card[0] * card[1]);
		}
		else if (n.size() % 4 == 0)
		{
			int check = card.size() / 4;
			for (int i = card.size() - 1; i >= card.size()/2 + check; i--)
				str_a += card[i] + '0';
			for (int i = card.size()/2 - check -1; i >= 0; i--)
				str_a += card[i] + '0';

			for (int i = card.size()/2 + check -1; i >= card.size()/2 - check; i--)
				str_b += card[i] + '0';
			str_result = to_string(stoi(str_a) * stoi(str_b));
		}
		else if(n.size()%2==0)
		{
			int check = card.size() / 4;
			for (int i = card.size() - 1; i >= card.size() / 2 + check; i--)
				str_a += card[i] + '0';
			for (int i = card.size() / 2 - check - 2; i >= 0; i--)
				str_a += card[i] + '0';

			for (int i = card.size() / 2 + check - 1; i >= card.size() / 2 - check-1; i--)
				str_b += card[i] + '0';
			str_result = to_string(stoi(str_a) * stoi(str_b));

			cout << str_a << ' ' << str_b << ' ';
			str_a = "";
			str_b = "";
			for (int i = card.size() - 1; i >= card.size() / 2 + check +1; i--)
				str_a += card[i] + '0';
			for (int i = card.size() / 2 - check - 1; i >= 0; i--)
				str_a += card[i] + '0';

			for (int i = card.size() / 2 + check; i >= card.size() / 2 - check; i--)
				str_b += card[i] + '0';
			cout << str_a << ' ' << str_b << ' ';
			str_result = max(str_result, to_string(stoi(str_a) * stoi(str_b)));
		}
		cout << str_result<<'\n';
		T--;
	}
}