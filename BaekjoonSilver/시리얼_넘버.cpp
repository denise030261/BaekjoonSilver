#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
	if (a.length() < b.length())
	{
		return true;
	}
	else if (a.length() > b.length())
	{
		return false;
	}
	else
	{
		int num_a = 0;
		int num_b = 0;

		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] - '0' >= 0 && a[i] - '0' <= 9)
			{
				num_a += a[i] - '0';
			}

			if (b[i] - '0' >= 0 && b[i] - '0' <= 9)
			{
				num_b += b[i] - '0';
			}
		}

		if (num_a < num_b)
		{
			return true;
		}
		else if (num_a > num_b)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < a.length(); i++)
			{
				if (a[i] < b[i])
					return true;
				else if (a[i] > b[i])
					return false;
				else
					continue;

			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<string> arr;
	cin >> N;

	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		arr.push_back(str);
	}

	sort(arr.begin(), arr.end(),compare);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i]<<'\n';
	}
}