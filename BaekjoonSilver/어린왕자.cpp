#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, x1, y1, x2, y2, n, cx, cy, r;
	int result = 0;
	cin >> T;
	while (T != 0)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> cx >> cy >> r;
			if (sqrt(pow(cx - x1, 2) + pow(cy - y1, 2)) < r && sqrt(pow(cx - x2, 2) + pow(cy - y2, 2)) < r)
				continue;
			else if (sqrt(pow(cx - x1, 2) + pow(cy - y1, 2)) < r || sqrt(pow(cx - x2, 2) + pow(cy - y2, 2)) < r)
				result++;
		}
		cout << result<<'\n';
		result = 0;
		T--;
	}

}