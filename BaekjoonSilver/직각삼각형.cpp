#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int result = 0;
	int x[1500];
	int y[1500];
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];

	double A, B, C;
	int x_vector[2];
	int y_vector[2];
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				A = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
				B = sqrt(pow(x[j] - x[k], 2) + pow(y[j] - y[k], 2));
				C = sqrt(pow(x[k] - x[i], 2) + pow(y[k] - y[i], 2));

				if (A < B + C)
				{
					x_vector[0] = x[i] - x[k];
					x_vector[1] = x[j] - x[k];
					y_vector[0] = y[i] - y[k];
					y_vector[1] = y[j] - y[k];
					if (x_vector[0] * x_vector[1] + y_vector[0] * y_vector[1] == 0)
						result++;
				}
				if (B < A + C)
				{
					x_vector[0] = x[j] - x[i];
					x_vector[1] = x[k] - x[i];
					y_vector[0] = y[j] - y[i];
					y_vector[1] = y[k] - y[i];
					if (x_vector[0] * x_vector[1] + y_vector[0] * y_vector[1] == 0)
						result++;
				}
				if (C < A + B)
				{
					x_vector[0] = x[i] - x[j];
					x_vector[1] = x[k] - x[j];
					y_vector[0] = y[i] - y[j];
					y_vector[1] = y[k] - y[j];
					if (x_vector[0] * x_vector[1] + y_vector[0] * y_vector[1] == 0)
						result++;
				}
			}
		}
	}

	cout << result;
}