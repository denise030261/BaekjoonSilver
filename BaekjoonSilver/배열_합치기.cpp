/*#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int num;
	int A, B;
	priority_queue<long long int, vector<long long int>, greater<long long int>> pq;

	cin >> A >> B;
	for (int i = 0; i < A; i++)
	{
		cin >> num;
		pq.push(num);
	}

	for (int i = 0; i < B; i++)
	{
		cin >> num;
		pq.push(num);
	}

	while (!pq.empty())
	{
		long long int temp = pq.top();
		cout << temp << ' ';
		pq.pop();
	}
}*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int num;
	int A, B;
	vector<long long int> v;

	cin >> A >> B;
	for (int i = 0; i < A; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < B; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
}