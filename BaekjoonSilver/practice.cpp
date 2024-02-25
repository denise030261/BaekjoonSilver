#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> q;
	int q_num = 0; int k_num = 0; int u = 0; int a = 0; int c = 0;
	int compare = 1;
	int result = -1;
	vector<int> k;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'q' && q_num >= u && q_num >= a && q_num >= c && q_num >= k_num)
		{
			q.push_back(i);
			q_num++;
		}
		else if (str[i] == 'u' && u < q_num)
			u++;
		else if (str[i] == 'a' && a < u)
			a++;
		else if (str[i] == 'c' && c < a)
			c++;
		else if (str[i] == 'k' && k_num < c)
		{
			k.push_back(i);
			k_num++;

			if (result == -1)
				result = 1;
			else
			{
				if (k[0] > q[compare])
				{
					compare++;
					result++;
				}
				else if (k[0] < q[compare])
				{
					k.erase(k.begin());
					q.erase(q.begin());
				}
			}
		}
	}

	if (q_num == u && u == a && a == c && c == k_num)
		cout << result;
	else
		cout << -1;
}