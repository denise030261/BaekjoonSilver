#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		bool correct = false;
		double x[4] = { 0, };
		double y[4] = { 0, };
		for (int j = 0; j < 4; j++)
			cin >> x[j] >> y[j];

		for (int j = 0; j < 4; j++)
		{
			double num[3] = { 0, };
			double vector_x[3] = { 0, };
			double vector_y[3] = { 0, };
			int point = 0;
			int check = 0;

			for (int k = 0; k < 4; k++)
				if (j != k)
				{
					num[point] = sqrt(pow(x[j] - x[k], 2) + pow(y[j] - y[k], 2)); //점과 점 사이의 거리
					vector_x[point] = x[j] - x[k];
					vector_y[point] = y[j] - y[k];
					point++;
				}

			if (num[0] == num[1])
			{
				check++;
				if (abs(vector_x[0] * vector_x[1] + vector_y[0] * vector_y[1]) == 0)
					correct = true;
			}

			if (num[0] == num[2])
			{
				check++;
				if (abs(vector_x[0] * vector_x[2] + vector_y[0] * vector_y[2]) == 0)
					correct = true;
			}

			if (num[1] == num[2])
			{
				check++;
				if (abs(vector_x[1] * vector_x[2] + vector_y[1] * vector_y[2]) == 0)
					correct = true;
			}

			if (check != 1)
			{
				correct = false;
				break;
			}

		}

		if (!correct)
			cout << 0 << '\n';
		else if(correct)
			cout << 1 << '\n';
	}
}