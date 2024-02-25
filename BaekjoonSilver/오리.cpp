#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> q; 
	vector<int> k;
	int q_num = 0; int k_num = 0; int u = 0; int a = 0; int c = 0; int result = 0; 
	int count[5] = { 0, };
	string str;
	bool plus = true; 
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'q')
		{
			q.push_back(i);
			count[0]++;
			q_num++;
		}
		else if (str[i] == 'u')
		{
			if(u < q_num)
				u++;
			count[1]++;
		}
		else if (str[i] == 'a')
		{
			if(a < u)
				a++;
			count[2]++;
		}
		else if (str[i] == 'c')
		{
			if(c < a)
				c++;
			count[3]++;
		}
		else if (str[i] == 'k')
		{
			if (k_num < c)
			{
				plus = true;
				k.push_back(i);
				k_num++;

				for (int j = 1; j < k.size(); j++)
				{
					if (k[0] < q[j])
					{
						k.erase(k.begin());
						q.erase(q.begin());
						plus = false;
						break;
					}
				}
				if (plus)
				{
					result++;
				}
			}
			count[4]++;
		}
	}

	if (q_num == u && u == a && a == c && c == k_num && 
		count[0] == count[1] && count[1] == count[2] && count[2] == count[3] && count[3] == count[4])
		cout << result;
	else
		cout << -1;
}