#include <iostream>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
	if (n == 0 || W == 0)
		return 0;

	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);

	else
		return max(
			val[n - 1]
			+ knapSack(W - wt[n - 1], wt, val, n - 1),
			knapSack(W, wt, val, n - 1));
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int health[20] = { 0, };
	int pleasure[20] = { 0, };
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		health[i] = num;
	}

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		pleasure[i] = num;
	}

	cout << knapSack(99, health, pleasure, N);
}