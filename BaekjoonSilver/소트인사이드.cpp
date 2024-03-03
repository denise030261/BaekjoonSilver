#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str;
	vector<int> answer;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		answer.push_back(str[i] - '0');
	}

	sort(answer.begin(), answer.end(),compare);

	for (int i = 0; i < str.length(); i++)
	{
		cout << answer[i];
	}
}