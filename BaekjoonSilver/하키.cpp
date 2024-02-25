#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int W, H, X, Y, P,R;
	int result = 0;
	cin >> W >> H >> X >> Y >> P;
	R = H / 2;

	for (int i = 0; i < P; i++)
	{
		int x, y;
		cin >> x >> y;

		if (x >= X && x <= X + W)
		{
			if (y >= Y && y <= Y + H)
			{
				result++;
				continue;
			}
		}

		if ((R >= sqrt(pow(x - X, 2) + pow(y - (Y + R), 2))) || (R >= sqrt(pow(x - (X+W), 2) + pow(y - (Y + R), 2))))
		{
			result++;
			continue;
		}
	}

	cout << result;
}