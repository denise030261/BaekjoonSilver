#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int K, N;
	int order = 0;
	vector<int> v;
	vector<int> output;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		v.push_back(i);

	while (!v.empty())
	{
		order += K-1;
		if (order < v.size())
		{
			output.push_back(v[order]);
			v.erase(v.begin() + order);
		}
		else
		{
			while(order>=v.size())
				order -= v.size();
			output.push_back(v[order]);
			v.erase(v.begin() + order);
		}
	}

	cout << "<";
	for (int i = 0; i < output.size(); i++)
	{
		if (output.size() - 1 == i)
			cout << output[i] << ">";
		else
			cout << output[i] << ", ";
	}
}