#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, x1, y1, r1, x2, y2, r2;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			cout << -1 << '\n';
			continue;
		}
		if (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) == r1 + r2)
			cout << 1 << '\n';
		else if (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) > r1 + r2)
			cout << 0 << '\n';
		else if (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) < r1 + r2)
		{
			int rad1 = r1;
			int rad2 = r2;
			if (r1 > r2)
			{
				rad1 = r2;
				rad2 = r1;
			}

			if (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) + rad1 == rad2)
				cout << 1 << '\n';
			else if (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) + rad1 > rad2)
				cout << 2 << '\n';
			else if (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) + rad1 < rad2)
				cout << 0 << '\n';
		}
	}
}