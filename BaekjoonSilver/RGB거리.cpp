#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N,R,G,B;
	int RGB[1001][3];
	RGB[0][0] = 0;
	RGB[0][1] = 0;
	RGB[0][2] = 0;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> R >> G >> B;
		RGB[i][0] = min(RGB[i - 1][1], RGB[i - 1][2]) + R;
		RGB[i][1] = min(RGB[i - 1][0], RGB[i - 1][2]) + G;
		RGB[i][2] = min(RGB[i - 1][0], RGB[i - 1][1]) + B;
	}

	cout << min(RGB[N][0],min( RGB[N][1], RGB[N][2]));
}