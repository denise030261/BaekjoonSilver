#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int Seong[2];
	int Professor[2];
	int InStudent = 0;
	bool Distance = false;
	bool Three = false;
	vector<pair<int, int>> Student;

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int num;
			cin >> num;
			if (num == 5)
			{
				Professor[0] = j + 1;
				Professor[1] = i + 1;
			}
			else if (num == 2)
			{
				Seong[0] = j + 1;
				Seong[1] = i + 1;
			}
			else if (num == 1)
			{
				Student.push_back(pair < int, int>(j + 1, i + 1));
			}
		}

	if (sqrt(pow(Seong[0] - Professor[0], 2) + pow(Seong[1] - Professor[1], 2)) >= 5)
		Distance = true;

	for (int i = 0; i < Student.size(); i++)
	{
		if ((Seong[0] <= Student[i].first && Student[i].first <= Professor[0])
			|| (Professor[0] <= Student[i].first && Student[i].first <= Seong[0]))
			if ((Seong[1] <= Student[i].second && Student[i].second <= Professor[1])
				|| (Professor[1] <= Student[i].second && Student[i].second <= Seong[1]))
				InStudent++;
	}

	if (InStudent >= 3)
		Three = true;

	if (Distance && Three)
		cout << 1;
	else
		cout << 0;
}