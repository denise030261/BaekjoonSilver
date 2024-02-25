#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T!=0)
	{
		int area = 0;
		int overlap = 0;

		int x[4] = { 0, };
		int y[4] = { 0, };
		int x_overlap[2] = { 0, };
		int y_overlap[2] = { 0, };

		for (int i = 0; i < 4; i++)
			cin >> x[i] >> y[i];	

		area = (x[1] - x[0]) * (y[1] - y[0]);
		
		if (x[2] >= x[0] && x[2] <= x[1])
			x_overlap[0] = x[2];
		else if (x[2] < x[0])
			x_overlap[0] = x[0];
		else if (x[2] > x[1])
			x_overlap[0] = x[1];

		if (y[2] >= y[0] && y[2] <= y[1])
			y_overlap[0] = y[2];
		else if (y[2] < y[0])
			y_overlap[0] = y[0];
		else if (y[2] > y[1])
			y_overlap[0] = y[1];
		
		if (x[3] >= x[0] && x[3] <= x[1])
			x_overlap[1] = x[3];
		else if (x[3] < x[0])
			x_overlap[1] = x[0];
		else if (x[3] > x[1])
			x_overlap[1] = x[1];

		if (y[3] >= y[0] && y[3] <= y[1])
			y_overlap[1] = y[3];
		else if (y[3] < y[0])
			y_overlap[1] = y[0];
		else if (y[3] > y[1])
			y_overlap[1] = y[1];

		cout << area-((x_overlap[1] - x_overlap[0]) * (y_overlap[1] - y_overlap[0]))<<'\n';
		T--;
	}
}
