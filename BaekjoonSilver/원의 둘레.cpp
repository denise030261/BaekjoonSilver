#include <iostream>
#include <cmath>
#include <iomanip>

#define PI 3.141592653589793

using namespace std;

int main()
{
	double x1, y1, x2, y2, x3, y3;
	double A, B, C, D, E, F, G;
	double dia;
	long double result;

	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
	{
		A = x2 - x1;
		B = y2 - y1;
		C = x3 - x1;
		D = y3 - y1;
		E = A * (x1 + x2) + B * (y1 + y2);
		F = C * (x1 + x3) + D * (y1 + y3);
		G = 2 * (A * (y3 - y2) - B * (x3 - x2));
		if (G == 0)
		{
			result = PI * sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) * 2;
			result *= 100;
			result = round(result);
			result /= 100;
			cout << setprecision(16);
			cout << result << '\n';
		}
		else
		{
			double x = (D * E - B * F) / G;
			double y = (A * F - C * E) / G;
			result = PI * sqrt(pow(x - x2, 2) + pow(y - y2, 2)) * 2;
			result *= 100;
			result = round(result);
			result /= 100;
			cout << setprecision(16);
			cout <<  result << '\n';
		}
	}

}