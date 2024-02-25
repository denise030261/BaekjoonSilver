#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int A, B, num;
	long long int sub = 0;
	set<long long int> Collect;
	cin >> A >> B;

	for (int i = 0; i < A; i++)
	{
		cin >> num;
		Collect.insert(num);
	}

	int pre;
	for (int i = 0; i < B; i++)
	{
		cin >> num;
		pre = Collect.size();
		Collect.insert(num);
		if (pre == Collect.size())
			sub++;
	}

	cout << Collect.size() - sub;
} 