#include <iostream>
#include <algorithm>

using namespace std;

long long a_par, a_chi, b_par, b_chi, result_par, result_chi;

int gcd(int a, int b)
{
	int tmp, n;

	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	while (b != 0)
	{
		n = a % b;
		a = b;
		b = n;
	}

	return a;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> a_chi >> a_par;
	cin >> b_chi >> b_par;

	result_par = a_par * b_par;
	result_chi = a_chi * b_par + b_chi * a_par;

	
	cout << result_chi / gcd(result_par, result_chi) << ' ' << result_par / gcd(result_par, result_chi);
}